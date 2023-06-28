#ifndef RISC_V_PREDICTOR_H
#define RISC_V_PREDICTOR_H
#include "bitset"

//adaptive two-level predictor
class Predictor{

public:
    bool predict_result[32]; //predict_result[i]表示RoB[i]的预测结果
    std::bitset<2> BHT[1024]; //branch_history_table,根据pc的后10位对应到一条确定的地址
    std::bitset<2> PHT[4096]; //pattern_history_table

    bool predict(const int &address);

};

#endif //RISC_V_PREDICTOR_H
