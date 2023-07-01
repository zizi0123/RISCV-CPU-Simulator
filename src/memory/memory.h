#ifndef RISC_V_MEMORY_H
#define RISC_V_MEMORY_H

#include "string"

class Memory {
private:
    unsigned char data[2000000]; //指令及数据，数组的一个单元存一个字节
    int num = 0; //总字节数
    int start_address = -1;
public:
    void Loadin();

    int GetNewIns();//往下读一条指令,返回一个32位无符号整数;pc+=4

    int UnsignedRead(const int &add, const int &size) ; //零扩展为32位

    int SignedRead(const int &add, const int &size); //符号扩展为32位

    void Write(const int &add, const int &x,const int &size);

    int pc; //program counter ：储存了下一条将要被读入的指令的地址
};


#endif //RISC_V_MEMORY_H
