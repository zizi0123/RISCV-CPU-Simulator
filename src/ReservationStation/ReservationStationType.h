#ifndef RISC_V_RESERVATIONSTATIONTYPR_H
#define RISC_V_RESERVATIONSTATIONTYPR_H
#include "string"

struct ReservationEle {
    std::string type;
    int entry; //在RoB中的对应编号
    int time = -1;
    int v1 = -1;
    int v2 = -1;
    int q1 = -1; //默认无依赖
    int q2 = -1; //默认无依赖
    int imm = 0;
    int pc;

    ReservationEle();

    ReservationEle (const int &,const std::string &_type,const int &pc); //初始化为：无依赖，未开始倒计时，entry记为RoB的队伍末端
};

struct SLEle{
    bool commit = false;
    int time = -1;
    int address;
    int value;
    int entry_num;
    std::string type;
};
#endif //RISC_V_RESERVATIONSTATIONTYPR_H
