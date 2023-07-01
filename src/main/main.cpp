#include "../memory/memory.h"
#include "../parser/parser.h"
#include "../RegisterFile/RegisterFile.h"
#include "../ReorderBuffer/ReorderBuffer.h"
#include "../ReservationStation/ReservationStation.h"

int main() {
    freopen("../../testcases/array_test1.data","r",stdin);
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
                predictor.predict_result[RoB.RearEntry()] = true;
            }else{
                predictor.predict_result[RoB.RearEntry()] = false;
            }
            RoB.branch = false;
        } else if (!RoB.Full() && !RoB.jump) {
            int pc = memory.pc;
            instruct new_ins = Process(memory.GetNewIns(), pc);
            RoB.FlowIn(new_ins); //Flowin时先默认状态为waiting,如果transmit成功，则改为executing
            if (new_ins.rd != -1) RF.AddDep(new_ins.rd, RoB.RearEntry());
        }

        //将指令发射到RS中
        for (int i = RoB.queue.front, j; i != RoB.queue.rear; i = j) { //对RoB中所有处于waiting状态的指令，尝试将其发射至RS中
            j = (i + 1) % RoB.queue.MaxSize; //下一个元素
            if (RoB.queue.queue[j].state == waiting) {
                if (RS.TryTransmit(RoB.queue.queue[j].instruction, j, RF)) RoB.queue.queue[j].state = executing;
            }
        }

        //处理RS
        std::vector<int> nums1;
        RS.TimeTraversal(nums1); //减少RS1、store_buffer队头中正在执行的指令的倒计时
        RS.SetReady(nums1, RoB); //对RS1、store_buffer队头倒计时结束的指令，向RoB发送，并且将本条指令从RS中删去
        RS.CDB(RoB);
        RS.SetExecute(RoB,memory);

        //commit
        if (!RoB.TryCommit(memory, RF, predictor)) {
            RoB.Clear();
            RS.Clear();
            RF.Clear();
        }

        RF.Flush();

        if (RoB.program_finish) return ((unsigned int) RF.GetValue(10)) & 255;
    }
}