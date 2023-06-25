#ifndef RISC_V_REORDERBUFFERTYPE_H
#define RISC_V_REORDERBUFFERTYPE_H
#include "string"

struct RoBEle{
    int entry;
    bool busy;
    std::string instruction;
    int result1;
    int result2;
    int destination;
};

struct instruct{
    int imm=0;
    int rd=0;
    int rs1=0;
    int rs2=0;
    int offset=0;
    std::string ins_type;
};
#endif //RISC_V_REORDERBUFFERTYPE_H
