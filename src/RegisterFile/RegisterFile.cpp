#include "RegisterFile.h"

void RegisterFile::ClearDep(int reg_num) {

}

void RegisterFile::AddDep(int reg_num, int ins_num) {

}

RegisterFile::RegisterFile() {
    regs[0]=RegisterElement(0);
}

RegisterElement::RegisterElement(const int &num, const bool &dep):ins_num(num),if_depend(dep) {}
