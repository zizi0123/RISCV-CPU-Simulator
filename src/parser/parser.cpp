#include "parser.h"

instruct Process(const int &a) { //输入一个32位整数
    instruct result;
    const int bits_10 = 1023;
    const int bits_8 = 255;
    const int bits_7 = 127;
    const int bits_6 = 63;
    const int bits_5 = 31;
    const int bits_3 = 7;
    int opcode = a & bits_7;
    if(a == 0x0ff00513){
        result.ins_type="return";
        return result;
    }
    if (opcode == LUI || opcode == AUIPC) {
        result.imm = ((a >> 12) << 12);
        result.rd = (a >> 7) & bits_5;
        if (opcode == LUI) {
            result.ins_type = "lui";
        } else {
            result.ins_type = "auipc";
        }
    } else if (opcode == JAL) {
        int tmp = a >> 7;
        result.rd = tmp & bits_5;
        result.ins_type = "jal";
        tmp >>= 5;
        result.imm = ((tmp >> 9) & bits_10) << 1;
        result.imm &= ((tmp >> 8) & 1) << 11;
        result.imm &= (tmp & bits_8) << 12;
        result.imm &= (tmp >> 19) << 20;
    } else if (opcode == JALR) {
        int tmp = a >> 7;
        result.rd = tmp & bits_5;
        result.ins_type = "jalr";
        tmp >>= 8;
        result.rs1 = tmp & bits_5;
        tmp >>= 5;
        result.imm = tmp;
    } else if (opcode == B) {
        int tmp = a >> 7;
        int imm1 = tmp & bits_5;
        result.imm = (imm1 >> 1) << 1;
        tmp >>= 5;
        int opcode2 = tmp & bits_3;
        if (opcode2 == 0) {
            result.ins_type = "beq";
        } else if (opcode2 == 1) {
            result.ins_type = "bne";
        } else if (opcode2 == 4) {
            result.ins_type = "blt";
        } else if (opcode2 == 5) {
            result.ins_type = "bge";
        } else if (opcode2 == 6) {
            result.ins_type = "bltu";
        } else if (opcode2 == 7) {
            result.ins_type = "bgeu";
        }
        tmp >>= 3;
        result.rs1 = tmp & bits_5;
        tmp >>= 5;
        result.rs2 = tmp & bits_5;
        tmp >>= 5;
        result.imm &= ((tmp & bits_6) << 5);
        result.imm &= ((imm1 & 1) << 11);
        tmp >>= 6;
        result.imm &= (tmp << 12);
    } else if (opcode == L) {
        int tmp = a >> 7;
        result.rd = tmp & bits_5;
        tmp >>= 5;
        int opcode2 = tmp & bits_3;
        if (opcode2 == 0) {
            result.ins_type = "lb";
        } else if (opcode2 == 1) {
            result.ins_type = "lh";
        } else if (opcode2 == 2) {
            result.ins_type = "lw";
        } else if (opcode2 == 4) {
            result.ins_type = "lbu";
        } else if (opcode2 == 5) {
            result.ins_type = "lhu";
        }
        tmp >>= 3;
        result.rs1 = tmp & bits_5;
        tmp >>= 5;
        result.imm = tmp;
    } else if (opcode == S) {
        int tmp = a >> 7;
        result.imm = tmp & bits_5;
        tmp >>= 5;
        int opcode2 = tmp & bits_3;
        if (opcode2 == 0) {
            result.ins_type = "sb";
        } else if (opcode2 == 1) {
            result.ins_type = "sh";
        } else if (opcode2 == 2) {
            result.ins_type = "sw";
        }
        tmp >>= 3;
        result.rs1 = tmp & bits_5;
        tmp >>= 5;
        result.rs2 = tmp & bits_5;
        tmp >>= 5;
        result.imm &= (tmp << 5);
    } else if (opcode == I) {
        int tmp = a >> 7;
        result.rd = tmp & bits_5;
        tmp >>= 5;
        int opcode2 = tmp & bits_3;
        if (opcode2 == 0 || opcode2 == 2 || opcode2 == 3 || opcode2 == 4 || opcode2 == 6 || opcode2 == 7) {
            if (opcode2 == 0) {
                result.ins_type = "addi";
            } else if (opcode2 == 2) {
                result.ins_type = "slti";
            } else if (opcode2 == 3) {
                result.ins_type = "sltiu";
            } else if (opcode2 == 4) {
                result.ins_type = "xori";
            } else if (opcode2 == 6) {
                result.ins_type = "ori";
            } else {
                result.ins_type = "andi";
            }
            tmp >>= 3;
            result.rs1 = tmp & bits_5;
            tmp >>= 5;
            result.imm = tmp;
        } else {
            if (opcode2 == 1) {
                result.ins_type = "slli";
            } else if (opcode2 == 5) {
                if (tmp >> 13 == 0) {
                    result.ins_type = "srli";
                } else {
                    result.ins_type = "srai";
                }
            }
            tmp >>= 3;
            result.rs1 = tmp & bits_5;
            tmp >>= 5;
            result.imm = tmp & bits_5;
        }
    } else if (opcode == R){
        int tmp = a >> 7;
        result.rd = tmp & bits_5;
        tmp >>= 5;
        int opcode2 = tmp & bits_3;
        if (opcode2 == 0) {
            if(tmp>>13 == 0) {
                result.ins_type = "add";
            }else{
                result.ins_type = "sub";
            }
        } else if (opcode2 == 1) {
            result.ins_type = "sll";
        } else if (opcode2 == 2) {
            result.ins_type = "slt";
        } else if (opcode2 == 3) {
            result.ins_type = "sltu";
        } else if (opcode2 == 4) {
            result.ins_type = "xor";
        } else if (opcode2 == 5) {
            if(tmp>>13 == 0) {
                result.ins_type = "srl";
            }else{
                result.ins_type = "sra";
            }
        } else if (opcode2 == 6) {
            result.ins_type = "or";
        } else if (opcode2 == 7) {
            result.ins_type = "and";
        }
        tmp >>= 3;
        result.rs1 = tmp & bits_5;
        tmp >>= 5;
        result.rs2 = tmp & bits_5;
    }
    return result;
}
