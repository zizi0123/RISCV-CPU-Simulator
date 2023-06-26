#ifndef RISC_V_UTILS_H
#define RISC_V_UTILS_H

#include "../ReorderBuffer/ReorderBufferType.h"
#include "../ReservationStation/ReservationStationType.h"
//实现一个可以用下标访问的queue
template<class T,int a>
class MyQueue {
public:
    const int MaxSize = a;
    T queue[32];
    int front;
    int rear;

    MyQueue();

    bool EnQueue(const T &x);

    bool DeQueue();

    T &Front();

    T &Back();

    bool Full();

    bool Empty();

    int size();

};

#endif //RISC_V_UTILS_H
