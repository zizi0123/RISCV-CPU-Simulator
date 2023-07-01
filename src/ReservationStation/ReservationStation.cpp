#include "ReservationStation.h"


//已保证，RS中必有空余的空间。
// 1.去检查rs1、rs2是否有依赖，若无，计入Vk(Vj)，Qk(Qj)=0;否则，使Qk(Qj)=register中的编号；
//如果RS堵塞，某条形如a = a + 1的指令发射失败，当下一次发射时，寄存器依赖已建立（依赖于本指令）。因此若寄存器依赖等于本指令编号，则视为无依赖。
void ReservationStation::Transmit(const instruct &new_ins, const int &entry_num, const RegisterFile &RF) {
    if (IsLS(new_ins.ins_type)) { //指令为load或store，需要访存，必须顺序执行
        ReservationEle a(entry_num, new_ins.ins_type, new_ins.pc);
        a.imm = new_ins.imm;
        if (RF.GetDep(new_ins.rs1) == -1) { //处理第一个寄存器
            a.v1 = RF.GetValue(new_ins.rs1);
        } else {
            a.q1 = RF.GetDep(new_ins.rs1);
        }
        if (new_ins.ins_type[0] == 's') { //Store
            if (RF.GetDep(new_ins.rs2) == -1) { //处理第二个寄存器
                a.v2 = RF.GetValue(new_ins.rs2);
            } else {
                a.q2 = RF.GetDep(new_ins.rs2);
            }
        }
        RS2.EnQueue(a); //发射
    } else { //指令只会访问寄存器，不会访存，可乱序执行
        int i;
        for (i = 0; i < 5; ++i) {
            if (RS1.alus[i].time == -2) break; //找一个空的
        }
        ReservationEle a(entry_num, new_ins.ins_type, new_ins.pc);
        if (new_ins.ins_type == "add" || new_ins.ins_type == "sub" || new_ins.ins_type == "sll" ||
            new_ins.ins_type == "slt" || new_ins.ins_type == "sltu" || new_ins.ins_type == "xor" ||
            new_ins.ins_type == "srl" || new_ins.ins_type == "sra" || new_ins.ins_type == "or" ||
            new_ins.ins_type == "and") { //无立即数
            if (RF.GetDep(new_ins.rs1) == -1) { //处理第一个寄存器
                a.v1 = RF.GetValue(new_ins.rs1);
            } else {
                a.q1 = RF.GetDep(new_ins.rs1);
            }
            if (RF.GetDep(new_ins.rs2) == -1) { //处理第二个寄存器
                a.v2 = RF.GetValue(new_ins.rs2);
            } else {
                a.q2 = RF.GetDep(new_ins.rs2);
            }
        } else {
            a.imm = new_ins.imm;
            if (!(new_ins.ins_type == "lui" || new_ins.ins_type == "auipc" || new_ins.ins_type == "jal")) { //有rs
                if (RF.GetDep(new_ins.rs1) == -1) { //处理第一个寄存器
                    a.v1 = RF.GetValue(new_ins.rs1);
                } else {
                    a.q1 = RF.GetDep(new_ins.rs1);
                }
                if (new_ins.ins_type[0] == 'b') {
                    if (RF.GetDep(new_ins.rs2) == -1) { //处理第二个寄存器
                        a.v2 = RF.GetValue(new_ins.rs2);
                    } else {
                        a.q2 = RF.GetDep(new_ins.rs2);
                    }
                }
            }
        }
        RS1.alus[i] = a; //发射
    }
}

void ReservationStation::TimeTraversal(std::vector<int> &a1) {
    for (int i = 0; i < 5; i++) {
        if (RS1.alus[i].time > 0) {
            --RS1.alus[i].time;
        } else if (RS1.alus[i].time == 0) { //倒计时已经结束！
            a1.push_back(i);
        }
    }

    if (!load_store_buffer.Empty() && load_store_buffer.Front().time > 0) --load_store_buffer.Front().time;

}

//时间已为0的指令执行ready操作，nums1记录了这些指令的编号
//将结果记入RoB中的result;
//RoB中的status=ready
void ReservationStation::SetReady(const std::vector<int> &nums1, ReorderBuffer &RoB) {
    //RS1:不访存
    for (auto i: nums1) {
        int entry_num = RS1.alus[i].entry;
        RoB.queue.queue[entry_num].state = ready;
        if (RS1.alus[i].type == "lui") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].imm; //rd
        } else if (RS1.alus[i].type == "auipc") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].imm + RS1.alus[i].pc; //rd
        } else if (RS1.alus[i].type == "jal") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].pc + 4; //rd
            RoB.queue.queue[entry_num].result2 = RS1.alus[i].pc + RS1.alus[i].imm; //pc
        } else if (RS1.alus[i].type == "jalr") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].pc + 4; //rd
            RoB.queue.queue[entry_num].result2 = (RS1.alus[i].imm + RS1.alus[i].v1) & (~1); //pc
        } else if (RS1.alus[i].type == "beq") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 == RS1.alus[i].v2); //if_jump
            RoB.queue.queue[entry_num].result2 = RS1.alus[i].pc + RS1.alus[i].imm; //pc
        } else if (RS1.alus[i].type == "bne") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 != RS1.alus[i].v2); //if_jump
            RoB.queue.queue[entry_num].result2 = RS1.alus[i].pc + RS1.alus[i].imm; //pc
        } else if (RS1.alus[i].type == "blt") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 < RS1.alus[i].v2); //if_jump
            RoB.queue.queue[entry_num].result2 = RS1.alus[i].pc + RS1.alus[i].imm; //pc
        } else if (RS1.alus[i].type == "bge") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 >= RS1.alus[i].v2); //if_jump
            RoB.queue.queue[entry_num].result2 = RS1.alus[i].pc + RS1.alus[i].imm; //pc
        } else if (RS1.alus[i].type == "bltu") {
            RoB.queue.queue[entry_num].result1 = (unsigned int) RS1.alus[i].v1 < (unsigned int) RS1.alus[i].v2; //if_jump
            RoB.queue.queue[entry_num].result2 = RS1.alus[i].pc + RS1.alus[i].imm; //pc
        } else if (RS1.alus[i].type == "bgeu") {
            RoB.queue.queue[entry_num].result1 = (unsigned int) RS1.alus[i].v1 >= (unsigned int) RS1.alus[i].v2; //if_jump
            RoB.queue.queue[entry_num].result2 = RS1.alus[i].pc + RS1.alus[i].imm; //pc
        } else if (RS1.alus[i].type == "addi") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 + RS1.alus[i].imm; //rd
        } else if (RS1.alus[i].type == "slti") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 < RS1.alus[i].imm); //rd
        } else if (RS1.alus[i].type == "sltiu") {
            RoB.queue.queue[entry_num].result1 = (unsigned int) RS1.alus[i].v1 < (unsigned int) RS1.alus[i].imm; //rd
        } else if (RS1.alus[i].type == "xori") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 ^ RS1.alus[i].imm); //rd
        } else if (RS1.alus[i].type == "ori") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 | RS1.alus[i].imm); //rd
        } else if (RS1.alus[i].type == "andi") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 & RS1.alus[i].imm); //rd
        } else if (RS1.alus[i].type == "slli") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 << RS1.alus[i].imm); //rd
        } else if (RS1.alus[i].type == "srli") {
            RoB.queue.queue[entry_num].result1 = ((unsigned int) RS1.alus[i].v1) >> RS1.alus[i].imm; //rd
        } else if (RS1.alus[i].type == "srai") {
            RoB.queue.queue[entry_num].result1 = (RS1.alus[i].v1 >> RS1.alus[i].imm); //rd
        } else if (RS1.alus[i].type == "add") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 + RS1.alus[i].v2; //rd
        } else if (RS1.alus[i].type == "sub") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 - RS1.alus[i].v2; //rd
        } else if (RS1.alus[i].type == "sll") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 << (RS1.alus[i].v2 & 31); //rd
        } else if (RS1.alus[i].type == "slt") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 < RS1.alus[i].v2; //rd
        } else if (RS1.alus[i].type == "sltu") {
            RoB.queue.queue[entry_num].result1 = (unsigned) RS1.alus[i].v1 < (unsigned) RS1.alus[i].v2; //rd
        } else if (RS1.alus[i].type == "xor") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 ^ RS1.alus[i].v2; //rd
        } else if (RS1.alus[i].type == "srl") {
            RoB.queue.queue[entry_num].result1 = ((unsigned int) RS1.alus[i].v1) >> (RS1.alus[i].v2 & 31); //rd
        } else if (RS1.alus[i].type == "sra") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 >> (RS1.alus[i].v2 & 31); //rd
        } else if (RS1.alus[i].type == "or") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 | RS1.alus[i].v2; //rd
        } else if (RS1.alus[i].type == "and") {
            RoB.queue.queue[entry_num].result1 = RS1.alus[i].v1 & RS1.alus[i].v2; //rd
        }
        RS1.alus[i].time = -2; //将此元素标记为空
    }

    //RS2:访存
    if (!load_store_buffer.Empty() && load_store_buffer.Front().time == 0) { //已经执行完毕
        int entry_num = load_store_buffer.Front().entry_num;
        RoB.queue.queue[entry_num].state = ready;
        RoB.queue.queue[entry_num].result1 = load_store_buffer.Front().value;
        RoB.queue.queue[entry_num].result2 = load_store_buffer.Front().address;
        if (load_store_buffer.Front().type[0] == 's') RoB.store_commit = false; //有一条从store_buffer发出的store指令还未commit！
        load_store_buffer.DeQueue();
    }
}


void ReservationStation::CDB(const ReorderBuffer &RoB) { //如果寄存器所依赖的RoB中指令已经Ready，则将结果置于v1/v2中，令q1/q2=-1
    for (auto &i: RS1.alus) {
        if (i.time == -1 && i.q1 != -1 && RoB.queue.queue[i.q1].state == ready) {
            i.v1 = RoB.queue.queue[i.q1].result1; //result1储存的是寄存器值
            i.q1 = -1;
        }
        if (i.time == -1 && i.q2 != -1 && RoB.queue.queue[i.q2].state == ready) {
            i.v2 = RoB.queue.queue[i.q2].result1;
            i.q2 = -1;
        }
    }
    if (!RS2.Empty()) {
        for (int i = RS2.FrontEntry();; i = (i + 1) % RS2.MaxSize) {
            if (RS2.queue[i].q1 != -1 && RoB.queue.queue[RS2.queue[i].q1].state == ready) {
                RS2.queue[i].v1 = RoB.queue.queue[RS2.queue[i].q1].result1;
                RS2.queue[i].q1 = -1;
            }
            if (RS2.queue[i].q2 != -1 && RoB.queue.queue[RS2.queue[i].q2].state == ready) {
                RS2.queue[i].v2 = RoB.queue.queue[RS2.queue[i].q2].result1;
                RS2.queue[i].q2 = -1;
            }
            if(i == RS2.RearEntry()) break;
        }
    }
}

//RS1:将寄存器的值已确定的指令开始倒计时
//RS2:将寄存器的值已确定的指令放入store_buffer,如果上一条store指令已commit,store_buffer的队头指令可开始倒计时
void ReservationStation::SetExecute(ReorderBuffer &RoB, Memory &memory) {
    for (auto &i: RS1.alus) {
        if (i.time == -1 && i.q1 == -1 && i.q2 == -1) {
            i.time = 1;
        }
    }

    if (!RS2.Empty()) {
        if (RS2.Front().q1 == -1 && RS2.Front().q2 == -1) {
            SLEle a;
            a.address = RS2.Front().imm + RS2.Front().v1;
            a.entry_num = RS2.Front().entry;
            a.type = RS2.Front().type;
            if (RS2.Front().type[0] == 's') { //store指令，值已经可以确定
                if (RS2.Front().type == "sb") {
                    a.value = RS2.Front().v2 & 127; //取0-7bits
                } else if (RS2.Front().type == "sh") {
                    a.value = RS2.Front().v2 & 65535; //取0-15bits
                } else {
                    a.value = RS2.Front().v2; //取0-32bits
                }
            }
            load_store_buffer.EnQueue(a);
            RS2.DeQueue();
        }
    }

    if (RoB.store_commit && !load_store_buffer.Empty() && load_store_buffer.Front().time == -1) { //只有store指令已经commit了才可以进行后面的load&store操作
        if (load_store_buffer.Front().type[0] == 's') {
            load_store_buffer.Front().time = 1;
        } else { //load
            load_store_buffer.Front().time = 3;
            if (load_store_buffer.Front().type == "lb") {
                load_store_buffer.Front().value = memory.SignedRead(load_store_buffer.Front().address, 1);
            } else if (load_store_buffer.Front().type == "lh") {
                load_store_buffer.Front().value = memory.SignedRead(load_store_buffer.Front().address, 2);
            } else if (load_store_buffer.Front().type == "lw") {
                load_store_buffer.Front().value = memory.SignedRead(load_store_buffer.Front().address, 4);
            } else if (load_store_buffer.Front().type == "lbu") {
                load_store_buffer.Front().value = memory.UnsignedRead(load_store_buffer.Front().address, 1);
            } else {
                load_store_buffer.Front().value = memory.UnsignedRead(load_store_buffer.Front().address, 2);
            }
        }
    }
}


void ReservationStation::Clear() {
    RS2.Clear(); //todo 查看reg[0]
    load_store_buffer.Clear();
    for (auto &i: RS1.alus) i.time = -2;
}


bool IsLS(const std::string &ins_type) {
    if (ins_type == "lb" || ins_type == "lh" || ins_type == "lw" || ins_type == "lbu" || ins_type == "lhu") return true;
    if (ins_type == "sb" || ins_type == "sh" || ins_type == "sw") return true;
    return false;
}

bool ALU::Full() const{
    return nums() == 5;
}

int ALU::nums() const {
    int num = 0;
    for(const auto& i:alus){
        if(i.time != -2) ++num;
    }
    return num;
}
