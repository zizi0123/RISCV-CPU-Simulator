#ifndef RISC_V_REORDERBUFFER_H
#define RISC_V_REORDERBUFFER_H
#include "../utils/utils.h"
#include "../ReorderBuffer/ReorderBufferType.h"


class ReorderBuffer{
public:
    MyQueue<RoBEle,32> queue;
    bool branch = false;

    int RearEntry() const;

    //流入一条新的指令
    void FlowIn(const instruct&);

    bool TryCommit(int &pc,bool &f); //若返回false,说明branch指令预判错误，清空CPU信息，引用传入的pc被更改。

    void Clear();

    bool Full();
};






#endif //RISC_V_REORDERBUFFER_H
