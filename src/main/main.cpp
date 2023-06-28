#include "../memory/memory.h"
#include "../parser/parser.h"
#include "../RegisterFile/RegisterFile.h"
#include "../ReorderBuffer/ReorderBuffer.h"
#include "../ReservationStation/ReservationStation.h"
#include "../predictor/predictor.h"
#include "queue"

int main() {
    Memory memory;
    RegisterFile RF;
    ReorderBuffer RoB;
    ReservationStation RS;
    Predictor predictor;
    memory.Loadin(); //载入所有内存中的数据
    while (true) { //执行到某语句会结束循环并且返回
        //指令流入
        if (RoB.branch) {
            if (predictor.predict(memory.pc - 4)) {
                memory.pc = memory.pc - 4 + RoB.offset;
                predictor.predict_result[RoB.RearEntry()] = true;
            }else{
                predictor.predict_result[RoB.RearEntry()] = false;
            }
            RoB.branch = false;
        } else if (!RoB.Full() && !RoB.jump) {
            instruct new_ins = Process(memory.GetNewIns(), memory.pc - 4);
            RoB.FlowIn(new_ins); //Flowin时先默认状态为waiting,如果transmit成功，则改为executing
            if (new_ins.rd != -1) RF.AddDep(new_ins.rd, RoB.RearEntry());
            for (int i = RoB.queue.front, j; i != RoB.queue.rear; i = j) { //对RoB中所有处于waiting状态的指令，尝试将其发射至RS中
                j = (i + 1) % RoB.queue.MaxSize; //下一个元素
                if (RoB.queue.queue[j].state == waiting) {
                    if (RS.TryTransmit(new_ins, j, RF)) RoB.queue.queue[j].state = executing;
                }
            }
        }

        //处理RS
        std::vector<int> nums1;
        RS.TimeTraversal(nums1); //处理RS1中已经在倒计时的指令，返回RS1中所有倒计时为0的指令的编号
        RS.SetReady(nums1, RoB);
        RS.CDB(RoB);
        RS.SetExecute();

        //commit
        if (!RoB.TryCommit(memory, RF, predictor)) {
            RoB.Clear();
            RS.Clear();
            RF.Clear();
        }
        if (RoB.program_finish) return ((unsigned int) RF.regs[10].value) & 255;
    }
}