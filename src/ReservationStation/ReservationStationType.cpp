#include "ReservationStationType.h"

ReservationEle::ReservationEle(const int &e,const std::string &_type,const int &_pc) {
    time = -1; //time = -2,表示单元为空；time=-1，表示单元已被占据，但仍未开始执行
    q1 = -1;
    q2 = -1;
    entry = e;
    type = _type;
    pc = _pc;
}

ReservationEle::ReservationEle() {
    time = -2; //表示该单元为空
    q1 = -1;
    q2 = -1;
}
