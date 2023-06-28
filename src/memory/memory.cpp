#include "memory.h"
#include "iostream"

void Memory::Loadin() { //todo 验证正确性
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
            data[num + 3] = (unsigned char) strtoul(piece.c_str(), nullptr, 16);
            for (int i = 1; i <= 3; ++i) {
                std::cin >> std::hex >> data[num + 3 - i];
            }
            num += 4;
        }
    }
    pc = start_address;
}

int Memory::GetNewIns() {
    int a = (int) (signed char) data[pc++] << 24;
    int b = ((int) data[pc++]) << 16;
    int c = ((int) data[pc++]) << 8;
    int d = (int) data[pc++];
    return a | b | c | d;
}

int Memory::UnsignedRead(const int &add, const int &size) const {
    int pos = add - start_address;
    if (size == 1) return (int) data[pos];
    if (size == 2) return ((int) data[pos] << 8) | ((int) data[pos + 1]);
    int a = (int)data[pos] << 24;
    int b = ((int) data[pos + 1]) << 16;
    int c = ((int) data[pos + 2]) << 8;
    int d = (int) data[pos + 3];
    return a | b | c | d;
}

int Memory::SignedRead(const int &add, const int &size) const {
    int pos = add - start_address;
    if (size == 1) return (int) (signed char) data[pos];
    if (size == 2) return ((int) (signed char) data[pos] << 8) | ((int) data[pos + 1]);
    int a = (int) (signed char) data[pos] << 24;
    int b = ((int) data[pos + 1]) << 16;
    int c = ((int) data[pos + 2]) << 8;
    int d = (int) data[pos + 3];
    return a | b | c | d;
}
