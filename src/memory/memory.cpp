#include "memory.h"
#include "iostream"
#include "bitset"

void Memory::Loadin() {
    char a;
    while (std::cin >> a) {
        if (a == '@') {
            int address;
            std::cin >> std::hex >> address;
            if (start_address == 0) {
                start_address = address;
                pc = address;
                num = 0;
            } else {
                int new_num = address - start_address;
                for (int i = num; i < new_num; ++i) data[i] = 0; //给中间间断的都填上0
                num = new_num;
            }
        } else {
            std::string piece;
            char b;
            std::cin >> b;
            piece += a;
            piece += b;
            data[num+3] = strtol(piece.c_str(), nullptr, 16);
            for (int i = 1; i <= 3; ++i) {
                std::cin >> piece;
                data[num+3-i] = strtol(piece.c_str(), nullptr, 16);
            }
            num+=4;
        }
    }
}

int Memory::GetNewIns() {
    int a=data[(pc++)-start_address];
    for(int i = 1;i<=3;++i){
        a=(a<<8)&data[(pc++)-start_address];
    }
    return a;
}
