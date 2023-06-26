#include "../memory/memory.h"
#include "../parser/parser.h"
#include "../RegisterFile/RegisterFile.h"
#include "../ReorderBuffer/ReorderBuffer.h"
#include "../ReservationStation/ReservationStation.h"
#include "../predictor/predictor.h"
#include "main.h"
#include "queue"

int main() {
    bool program_finish = false;
    Memory memory;
    RegisterFile RF;
    ReorderBuffer RoB;
    ReservationStation RS;
    Predictor predictor;
    memory.Loadin(); //载入所有内存中的数据
    while (true) { //执行到某语句会结束循环并且返回
        //指令流入
        if (RoB.branch) {
            //todo 进行分支预测,决定是否修改PC
            RoB.branch = false;
        } else if (!RoB.Full()) {
            instruct new_ins = Process(memory.GetNewIns());
            RoB.FlowIn(new_ins); //Flowin时先默认状态为waiting,如果transmit成功，则改为executing
            if (new_ins.ins_type[0] == 'b') RoB.branch = true; //分支指令
            RS.TryTransmit(new_ins, RoB,RF);
        }

        //处理RS
        std::vector<int>nums = RS.TimeTraversal();
        RS.SetReady(nums,RoB);
        RS.CDB(nums);
        RS.ExecuteTraversal();

        //commit
        if(!RoB.TryCommit(memory.pc,program_finish)){
            RoB.Clear();
            RS.Clear();
            RF.Clear();
        }
        if(program_finish) return ((unsigned int)RF.regs[10].ins_num)&255;
    }
}