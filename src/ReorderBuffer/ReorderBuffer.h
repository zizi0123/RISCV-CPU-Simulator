#ifndef RISC_V_REORDERBUFFER_H
#define RISC_V_REORDERBUFFER_H
#include "../utils/utils.h"
#include "../ReorderBuffer/ReorderBufferType.h"
#include "../RegisterFile/RegisterFile.h"
#include "../predictor/predictor.h"
#include "../memory/memory.h"


class ReorderBuffer{
public:
    MyQueue<RoBEle,32> queue;
    bool branch = false;//上一条指令是否是branch
    bool jump = false; //是否存在未commit的jump指令
    bool store_commit = true;
    bool program_finish = false;
    int offset; //branch指令中pc的跳转距离
    int time; //倒计时

    //流入一条新的指令
    void FlowIn(const instruct&);

    bool TryCommit(Memory &memory, RegisterFile &RF,Predictor & ); //若返回false,说明branch指令预判错误，清空CPU信息，引用传入的pc被更改。

    void Clear();

    bool Full();

    void PrintCommit();
};






#endif //RISC_V_REORDERBUFFER_H
