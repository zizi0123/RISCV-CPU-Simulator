#include "ReorderBuffer.h"
#include "iostream"
bool ReorderBuffer::Full() {
    return queue.Full();
}

void ReorderBuffer::FlowIn(const instruct &new_ins) {
    RoBEle x = RoBEle(new_ins);
    x.state = waiting;
    queue.EnQueue(x);
    queue.Back().entry = queue.rear;
    if (new_ins.ins_type[0] == 'b') {
        branch = true; //分支指令
        offset = new_ins.imm;
    } else if (new_ins.ins_type[0] == 'j') {
        jump = true; //如果是直接跳转指令，也需要停止流入
    }
}

int ReorderBuffer::RearEntry() const {
    return queue.rear;
}

//若返回false,说明branch指令预判错误.
bool ReorderBuffer::TryCommit(Memory &memory, RegisterFile &RF, Predictor &predictor) {
    if (queue.Front().state != ready && queue.Front().state != committing) return true;
    std::string type = queue.Front().instruction.ins_type;
    if (queue.Front().state == ready) {
        if (type == "lui" || type == "auipc") {
            RF.SetValue(queue.Front().instruction.rd, queue.Front().result1);
            //如果此寄存器的依赖就是本条指令，则需要清除依赖标记
            if (RF.GetDep(queue.Front().instruction.rd) == queue.front + 1)
                RF.SetDep(queue.Front().instruction.rd, -1);
            std::cout<<"commit instruction pc:"<<std::hex<<queue.Front().instruction.pc<<' '<<queue.Front().instruction.ins_type<<std::endl;
            queue.DeQueue();
        } else if (type == "jal" || type == "jalr") {
            RF.SetValue(queue.Front().instruction.rd, queue.Front().result1);
            memory.pc = queue.Front().result2;
            jump = false; //jump指令已被commit
            if (RF.GetDep(queue.Front().instruction.rd) == queue.front + 1)
                RF.SetDep(queue.Front().instruction.rd, -1);
            std::cout<<"commit instruction pc:"<<std::hex<<queue.Front().instruction.pc<<' '<<queue.Front().instruction.ins_type<<std::endl;
            queue.DeQueue();
        } else if (type[0] == 'b') {
            bool result = (queue.Front().result1 == predictor.predict_result[queue.front + 1]);
            //预判错误！
            if (!result) {
                if (queue.Front().result1) { //本应跳转
                    memory.pc = queue.Front().result2;
                } else { //本不应跳转
                    memory.pc = queue.Front().instruction.pc + 4;
                }
            }
            //修改对应的二位饱和计数器
            std::bitset<2> history = predictor.BHT[queue.Front().instruction.pc & 1023];
            unsigned int num = ((queue.Front().instruction.pc & 1023) << 2) + history.to_ulong(); //计数器编号
            if (queue.Front().result1) { //跳转
                if (predictor.PHT[num].to_ulong() != 3) {
                    predictor.PHT[num] = std::bitset<2>(predictor.PHT[num].to_ulong() + 1);
                }
            } else { //不跳转
                if (predictor.PHT[num].to_ulong() != 0) {
                    predictor.PHT[num] = std::bitset<2>(predictor.PHT[num].to_ulong() - 1);
                }
            }
            //在预测器中记录本次跳转的结果
            predictor.BHT[queue.Front().instruction.pc & 1023] <<= 1;
            if (!queue.Front().result1) {
                predictor.BHT[queue.Front().instruction.pc & 1023].reset(0); //设为0
            } else {
                predictor.BHT[queue.Front().instruction.pc & 1023].set(0); //设为1
            }
            std::cout<<"commit instruction pc:"<<std::hex<<queue.Front().instruction.pc<<' '<<queue.Front().instruction.ins_type<<std::endl;
            queue.DeQueue();
            return result;
        } else if (type == "lb" || type == "lh" || type == "lw" || type == "lbu" || type == "lhu") {
            RF.SetValue(queue.Front().instruction.rd, queue.Front().result1);
            if (RF.GetDep(queue.Front().instruction.rd) == queue.front + 1)
                RF.SetDep(queue.Front().instruction.rd, -1);
            std::cout<<"commit instruction pc:"<<std::hex<<queue.Front().instruction.pc<<' '<<queue.Front().instruction.ins_type<<std::endl;
            queue.DeQueue();
        } else if (type == "sb" || type == "sh" || type == "sw") { //需要三个周期
            queue.Front().state = committing;
            time = 2;
        } else if (type == "return") {
            program_finish = true;
            std::cout<<"commit instruction pc:"<<std::hex<<queue.Front().instruction.pc<<' '<<queue.Front().instruction.ins_type<<std::endl;
            queue.DeQueue();
        } else {
            RF.SetValue(queue.Front().instruction.rd, queue.Front().result1);
            if (RF.GetDep(queue.Front().instruction.rd) == queue.front + 1)
                RF.SetDep(queue.Front().instruction.rd, -1);
            std::cout<<"commit instruction pc:"<<std::hex<<queue.Front().instruction.pc<<' '<<queue.Front().instruction.ins_type<<std::endl;
            queue.DeQueue();
        }
    } else {
        if (time != 0) {
            --time;
        } else {
            if (type == "sb") {
                memory.Write(queue.Front().result2, queue.Front().result1, 1);
            } else if (type == "sh") {
                memory.Write(queue.Front().result2, queue.Front().result1, 2);
            } else {
                memory.Write(queue.Front().result2, queue.Front().result1, 4);
            }
            store_commit = true; //store指令已经commit;
            std::cout<<"commit instruction pc:"<<std::hex<<queue.Front().instruction.pc<<' '<<queue.Front().instruction.ins_type<<std::endl;
            queue.DeQueue();
        }
    }
    return true;
}

void ReorderBuffer::Clear() {
    queue.Clear();
    branch = false;//上一条指令是否是branch
    jump = false; //是否存在未commit的jump指令
    store_commit = true;
    program_finish = false;
}

