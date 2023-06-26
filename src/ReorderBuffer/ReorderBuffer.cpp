#include "ReorderBuffer.h"

bool ReorderBuffer::Full() {
    return queue.Full();
}

void ReorderBuffer::FlowIn(const instruct &new_ins) {
    RoBEle x = RoBEle(new_ins);
    x.state = waiting;
    queue.EnQueue(x);
    x.entry = queue.rear;
}
