#ifndef RISC_V_UTILS_H
#define RISC_V_UTILS_H

#include "../ReorderBuffer/ReorderBufferType.h"

//实现一个可以用下标访问的queue
class MyQueue {
public:
    const int MaxSize = 32;
    RoBEle queue[32];
    int front;
    int rear;

    MyQueue();

    bool EnQueue(const RoBEle &x);

    bool DeQueue();

    RoBEle &Front();

    RoBEle &Back();

    bool Full();

    bool Empty();

};

#endif //RISC_V_UTILS_H
