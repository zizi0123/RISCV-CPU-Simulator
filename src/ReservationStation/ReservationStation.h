#ifndef RISC_V_RESERVATIONSTATION_H
#define RISC_V_RESERVATIONSTATION_H

#include "vector"
#include "ReservationStationType.h"
#include "../ReorderBuffer/ReorderBufferType.h"
#include "../ReorderBuffer/ReorderBuffer.h"
#include "../RegisterFile/RegisterFile.h"

class ReservationStation {
public:
    //load,store,jump,cmp,shift,set,branch
    ReservationEle all_type_RS[21];

    //将一条新的指令发射到对应的RS中，成功则更改RoB队尾元素状态为executing，失败则改为waiting
    void TryTransmit(const instruct &new_ins, ReorderBuffer &RoB, const RegisterFile &RF);

    //遍历时间，把已经开始执行的倒计时减一,返回时间为0的指令的all_type_RS编号
    std::vector<int> TimeTraversal();

    //对时间已为0的指令执行ready操作
    void SetReady(const std::vector<int> &nums, ReorderBuffer &RoB);

    //若有Qj(Qk)=entry，则令Vj(Vk)=result，Qj(Qk)=0;
    void CDB(const std::vector<int> &entries);

    //若有指令qj==0&&qi==0,则set time，开始执行
    void ExecuteTraversal();

    //branch指令预判错误，清空
    void Clear();


};

#endif //RISC_V_RESERVATIONSTATION_H
