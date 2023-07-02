

#ifndef RISC_V_MAIN_H
#define RISC_V_MAIN_H

#include "iostream"
#include "random"
#include "algorithm"
#include "../memory/memory.h"
#include "../parser/parser.h"
#include "../RegisterFile/RegisterFile.h"
#include "../ReorderBuffer/ReorderBuffer.h"
#include "../ReservationStation/ReservationStation.h"

void
FetchAndDecode(ReorderBuffer &RoB, Predictor &predictor, Memory &memory, ReservationStation &RS, RegisterFile &RF) {
    if (RoB.branch) { //上一条流入的指令是条件跳转
        if (predictor.predict(memory.pc - 4)) {
            memory.pc = memory.pc - 4 + RoB.offset;
            predictor.predict_result[RoB.queue.RearEntry()] = true;
        } else {
            predictor.predict_result[RoB.queue.RearEntry()] = false;
        }
        RoB.branch = false;
    } else if (!RoB.Full() && !RoB.jump) {
        if(!RoB.queue.Empty() && RoB.queue.Back().state == waiting) return;
        int pc = memory.pc;
        instruct new_ins = Process(memory.GetNewIns(), pc);
        if ((IsLS(new_ins.ins_type) && RS.RS2.Full()) ||
            (!IsLS(new_ins.ins_type) && RS.RS1.Full())) { //如果RS中没有空间，就不允许流入这条指令
            memory.pc -= 4;
        } else {
            RoB.FlowIn(new_ins); //Flowin时先默认状态为waiting,如果transmit成功，则改为executing
        }
    }
}


void Issue(ReorderBuffer &RoB, ReservationStation &RS, RegisterFile &RF) {
    if (!RoB.queue.Empty() && RoB.queue.Back().state == waiting) {
        if (RoB.queue.Back().instruction.rd != -1) RF.SetDep(RoB.queue.Back().instruction.rd, RoB.queue.RearEntry());
        RS.Issue(RoB.queue.Back().instruction, RoB.queue.RearEntry(), RF);
        RoB.queue.Back().state = executing;
    }
}

void Execute(ReservationStation &RS, ReorderBuffer &RoB, Memory &memory) {
    RS.TimeTraversal(); //减少RS1、store_buffer队头中正在执行的指令的倒计时
    RS.SetExecute(RoB, memory);
}

void WriteBack(ReservationStation &RS,ReorderBuffer &RoB){
    RS.SetReady(RoB); //对RS1、store_buffer队头倒计时结束的指令，向RoB发送，并且将本条指令从RS中删去
    RS.CDB(RoB);
}

void Commit(ReorderBuffer &RoB,Memory &memory,RegisterFile &RF,Predictor &predictor,ReservationStation &RS){
    if (!RoB.TryCommit(memory, RF, predictor)) {
        RoB.Clear();
        RS.Clear();
        RF.Clear();
    }
}

#endif //RISC_V_MAIN_H
