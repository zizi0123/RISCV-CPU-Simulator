#include "memory.h"
#include "iostream"

void Memory::Loadin() { //todo 验证正确性
    char a;
    while (std::cin >> a) {
        if (a == '@') {
            int address;
            std::cin >> std::hex >> address;
            if (start_address == -1) {
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
            data[num] = (unsigned char) strtoul(piece.c_str(), nullptr, 16);
            for (int i = 1; i <= 3; ++i) {
                unsigned short x;
                std::cin >> std::hex >> x;
                data[num + i] = (unsigned char) x;
            }
            num += 4;
        }
    }
    pc = start_address;
}

int Memory::GetNewIns() {
    int x = pc;
    pc+=4;
    return UnsignedRead(x,4);
}

int Memory::UnsignedRead(const int &add, const int &size)  {
    int pos = add - start_address;
    if (size == 1) return (int) data[pos];
    if (size == 2) return (int)(*(reinterpret_cast<unsigned short *>(data + pos))) ;
    return (int)(*(reinterpret_cast<unsigned int *>(data + pos)));
}

int Memory::SignedRead(const int &add, const int &size)  {
    int pos = add - start_address;
    if (size == 1) return (int) (signed char) data[pos];
    if (size == 2) return (int)(*(reinterpret_cast<short *>(data + pos))) ;
    return (int)(*(reinterpret_cast<int *>(data + pos)));
}

void Memory::Write(const int &add, const int &x, const int &size) {
    int pos = add - start_address;
    if (size == 1) {
        data[pos] = x;
    } else if (size == 2) {
        *(reinterpret_cast<u_int16_t*>(data+pos)) = x;
    } else {
        *(reinterpret_cast<u_int32_t*>(data+pos)) = x;
    }
}
