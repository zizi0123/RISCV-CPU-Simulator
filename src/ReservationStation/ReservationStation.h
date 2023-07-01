#ifndef RISC_V_RESERVATIONSTATION_H
#define RISC_V_RESERVATIONSTATION_H

#include "vector"
#include "ReservationStationType.h"
#include "../ReorderBuffer/ReorderBufferType.h"
#include "../ReorderBuffer/ReorderBuffer.h"
#include "../RegisterFile/RegisterFile.h"
#include "../memory/memory.h"
#include "../utils/utils.h"

class ALU{
public:
    ReservationEle alus[5];
    int nums()const;
    bool Full() const;
};

class ReservationStation {

public:
    ALU RS1; //只会访问寄存器，不会访问内存；   RS1:time==-2:空 time==-1:已有元素，但还未开始执行
    MyQueue<ReservationEle,5> RS2; //Load&Store,会访问内存；
    MyQueue<SLEle,32> load_store_buffer;

    //将一条新的指令发射到对应的RS中，返回是否成功
    void Transmit(const instruct &new_ins, const int &, const RegisterFile&RF);

    //遍历时间，把已经开始执行的倒计时减一,返回时间为0的指令的all_type_RS编号
    void TimeTraversal(std::vector<int> &);

    //对时间已为0的指令执行ready操作
    void SetReady(const std::vector<int> &, ReorderBuffer &RoB);

    //若有Qj(Qk)=entry，则令Vj(Vk)=result，Qj(Qk)=0;
    void CDB(const ReorderBuffer &RoB);

    //若有指令qj==0&&q1==0,则set time，开始执行
    void SetExecute(ReorderBuffer &RoB, Memory &memory);



    //branch指令预判错误，清空
    void Clear();


};

bool IsLS(const std::string &ins_type);

#endif //RISC_V_RESERVATIONSTATION_H
