#ifndef RISC_V_RESERVATIONSTATIONTYPR_H
#define RISC_V_RESERVATIONSTATIONTYPR_H
enum reservation_type {
    load, jump, cmp, store, shift, set
};
enum ins_type {
    ADD,
};  //todo 补充类型
struct ReservationEle {
    ins_type type;
    bool busy = false;
    int entry; //在RoB中的对应编号
    int time = -1;
    int vi = -1;
    int vj = -1;
    int qi = 0;
    int qj = 0;
    int imm = 0;
};
#endif //RISC_V_RESERVATIONSTATIONTYPR_H
