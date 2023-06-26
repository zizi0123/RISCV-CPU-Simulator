#include "ReorderBuffer.h"

bool ReorderBuffer::Full() {
    return queue.Full();
}

void ReorderBuffer::FlowIn(const instruct &new_ins) {
    RoBEle x = RoBEle(new_ins);
    x.state = waiting;
    queue.EnQueue(x);
    x.entry = RearEntry();
    if (new_ins.ins_type[0] == 'b') branch = true; //分支指令
}

int ReorderBuffer::RearEntry() const {
    return queue.rear;
}
