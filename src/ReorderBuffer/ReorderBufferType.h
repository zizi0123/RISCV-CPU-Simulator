#ifndef RISC_V_REORDERBUFFERTYPE_H
#define RISC_V_REORDERBUFFERTYPE_H
#include "string"

enum RoBstate{waiting,executing,ready};


struct instruct{
    int imm=0;
    int rd=0;
    int rs1=0;
    int rs2=0;
    int offset=0;
    std::string ins_type;
};

struct RoBEle{
    int entry;
//    bool busy= false;
    instruct instruction;
    int result1;
    int result2;
    RoBstate state;
//    int destination;
    RoBEle() = default;

    explicit RoBEle(const instruct&ins);
};
#endif //RISC_V_REORDERBUFFERTYPE_H
