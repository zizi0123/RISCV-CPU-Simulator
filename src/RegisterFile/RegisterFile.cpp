#include "RegisterFile.h"


void RegisterFile::AddDep(int reg_num, int ins_num) {
    if (reg_num == 0) return; //x0不会被修改
    regs_new[reg_num].depend = ins_num;
}

RegisterFile::RegisterFile() {
    regs_old[0] = RegisterElement(0);
    regs_new[0] = RegisterElement(0);
}

void RegisterFile::Clear() {
    for (int i = 0; i < 32; ++i) {
        regs_new[i].depend = -1;
        regs_old[i].depend = -1;
    }
}

void RegisterFile::SetDep(const int &reg_num, const int &ins_num) {
    if (reg_num == 0) return; //x0不会被修改
    regs_new[reg_num].depend = ins_num;
}

void RegisterFile::SetValue(const int &reg_num, const int &value) {
    if (reg_num == 0) return;
    regs_new[reg_num].value = value;
}

int RegisterFile::GetDep(const int &reg_num) const {
    return regs_old[reg_num].depend;
}

int RegisterFile::GetValue(const int &reg_num) const {
    return regs_old[reg_num].value;
}

void RegisterFile::Flush() {
    for (int i = 0; i < 32; ++i) regs_old[i] = regs_new[i];
}

RegisterElement::RegisterElement(const int &num) : value(num), depend(-1) {}
