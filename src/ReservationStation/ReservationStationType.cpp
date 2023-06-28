#include "ReservationStationType.h"

ReservationEle::ReservationEle(const int &e,const std::string &_type,const int &_pc) {
    time = -1;
    q1 = -1;
    q2 = -1;
    entry = e;
    type = _type;
    pc = _pc;
}

ReservationEle::ReservationEle() {
    time = -1;
    q1 = -1;
    q2 = -1;
}
