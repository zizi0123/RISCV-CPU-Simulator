#include "../ReorderBuffer/ReorderBufferType.h"
#include "bitset"

const unsigned short LUI = std::bitset<7>(0110111).to_ulong();
const unsigned short AUIPC = std::bitset<7>(0010111).to_ulong();
const unsigned short JAL = std::bitset<7>(1101111).to_ulong();
const unsigned short JALR = std::bitset<7>(1100111).to_ulong();
const unsigned short B = std::bitset<7>(1100011).to_ulong();
const unsigned short L = std::bitset<7>(0000011).to_ulong();
const unsigned short S = std::bitset<7>(0100011).to_ulong();
const unsigned short I = std::bitset<7>(0010011).to_ulong();
const unsigned short R = std::bitset<7>(0110011).to_ulong();

//将一个32位指令转化成解析后的结构体instruct
instruct Process(const int&a,const int &my_pc);
