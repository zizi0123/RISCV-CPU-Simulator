#include "RegisterFile.h"

void RegisterFile::ClearDep(int reg_num) {

}

void RegisterFile::AddDep(int reg_num, int ins_num) {

}

RegisterFile::RegisterFile() {
    regs[0]=RegisterElement(0);
}

void RegisterFile::Clear() {
    for(auto i : regs) i.depend = -1;
}

RegisterElement::RegisterElement(const int &num, const bool &dep): value(num), depend(dep) {}
