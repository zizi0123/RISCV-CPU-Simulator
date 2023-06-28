#ifndef RISC_V_REORDERBUFFERTYPE_H
#define RISC_V_REORDERBUFFERTYPE_H
#include "string"

enum RoBstate{waiting,executing,ready,committing};


struct instruct{
    int imm=0;
    unsigned int rd=-1; //表示没有结果寄存器
    unsigned int rs1=0;
    unsigned int rs2=0;
    int offset=0;
    int pc; //本指令的地址
    std::string ins_type;
};

struct RoBEle{
    int entry;
    instruct instruction;
    int result1; //结果寄存器rd的值或branch指令的if_jump
    int result2;
    RoBstate state;
    RoBEle() = default;

    explicit RoBEle(const instruct&ins);
};
#endif //RISC_V_REORDERBUFFERTYPE_H
