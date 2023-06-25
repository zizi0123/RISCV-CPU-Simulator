#ifndef RISC_V_MEMORY_H
#define RISC_V_MEMORY_H

#include "string"

class Memory {
private:
    int data[100000]; //指令及数据，数组的一个单元存一个字节
    int num = 0; //总字节数
    int start_address = 0;
public:
    void Loadin();

    int GetNewIns();//往下读一条指令,返回一个32位整数

    int Read(const int &add, const int &size);

    void Write(const int &add, const int &x);

    int pc;
};


#endif //RISC_V_MEMORY_H
