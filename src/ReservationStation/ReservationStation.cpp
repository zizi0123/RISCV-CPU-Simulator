#include "ReservationStation.h"


// 1.去检查rs1、rs2是否有依赖，若无，计入Vk(Vj)，Qk(Qj)=0;否则，使Qk(Qj)=register中的编号；
// 2.将Register File中结果寄存器的编号改为本指令编号
void ReservationStation::TryTransmit(const instruct &new_ins, ReorderBuffer &RoB, RegisterFile &RF) {
    if(new_ins.ins_type == "auipc"){

    }else if ()
}
