#include "iostream"
#include "../memory/memory.h"
#include "../parser/parser.h"
#include "../RegisterFile/RegisterFile.h"
#include "../ReorderBuffer/ReorderBuffer.h"
#include "../ReservationStation/ReservationStation.h"

int main() {
//    freopen("../../superloop.data", "r", stdin);
//    freopen("ans.out", "w", stdout);
    Memory memory;
    RegisterFile RF;
    ReorderBuffer RoB;
    ReservationStation RS;
    Predictor predictor;
    memory.Loadin(); //载入所有内存中的数据
    int cycle_counter = 0;
    while (true) { //执行到某语句会结束循环并且返回
        ++cycle_counter;
        //指令流入
        if (RoB.branch) { //上一条流入的指令是条件跳转
            if (predictor.predict(memory.pc - 4)) {
                memory.pc = memory.pc - 4 + RoB.offset;
                predictor.predict_result[RoB.queue.RearEntry()] = true;
            } else {
                predictor.predict_result[RoB.queue.RearEntry()] = false;
            }
            RoB.branch = false;
        } else if (!RoB.Full() && !RoB.jump) {
            int pc = memory.pc;
            instruct new_ins = Process(memory.GetNewIns(), pc);
            if ((IsLS(new_ins.ins_type) && RS.RS2.Full()) ||
                (!IsLS(new_ins.ins_type) && RS.RS1.Full())) { //如果RS中没有空间，就不允许流入这条指令
                memory.pc -= 4;
            } else {
                RoB.FlowIn(new_ins); //Flowin时先默认状态为waiting,如果transmit成功，则改为executing
                if (new_ins.rd != -1) RF.SetDep(new_ins.rd, RoB.queue.RearEntry());
            }
        }

        //将指令发射到RS中
        //需要保证，当某一条指令被发射时，它的后续指令一定还未流入。否则，在寄存器依赖上将会存在问题。
        if (RoB.queue.Back().state == waiting) {
            RS.Transmit(RoB.queue.Back().instruction, RoB.queue.RearEntry(), RF);
            RoB.queue.Back().state = executing;
        }

        //处理RS
        std::vector<int> nums1;
        RS.TimeTraversal(nums1); //减少RS1、store_buffer队头中正在执行的指令的倒计时
        RS.SetReady(nums1, RoB); //对RS1、store_buffer队头倒计时结束的指令，向RoB发送，并且将本条指令从RS中删去
        RS.CDB(RoB);
        RS.SetExecute(RoB, memory);

        //commit
        if (!RoB.TryCommit(memory, RF, predictor)) {
            RoB.Clear();
            RS.Clear();
            RF.Clear();
        }

        RF.Flush();

        if (RoB.program_finish) {
//            std::cout << "PROGRAM FINISH!\n";
            std::cout << (((unsigned int) RF.GetValue(10)) & 255);
            return 0;
        }
    }
}