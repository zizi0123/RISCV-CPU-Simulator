#ifndef RISC_V_RESERVATIONSTATIONTYPR_H
#define RISC_V_RESERVATIONSTATIONTYPR_H
#include "string"

struct ReservationEle {
    std::string type;
//    bool busy = false;
    int entry; //在RoB中的对应编号
    int time = -1;
    int vi = -1;
    int vj = -1;
    int qi = 0; //默认无依赖
    int qj = 0; //默认无依赖
    int imm = 0;

    void init(const int &); //初始化为：无依赖，未开始倒计时，entry记为RoB的队伍末端
};
#endif //RISC_V_RESERVATIONSTATIONTYPR_H
