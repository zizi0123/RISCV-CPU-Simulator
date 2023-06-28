#include "predictor.h"

bool Predictor::predict(const int &address) {
    std::bitset<2> history = BHT[address&1023];
    unsigned int num = ((address&1023)<<2)+history.to_ulong();
    std::bitset<2> saturation_counter = PHT[num];
    return saturation_counter.test(1); //二位饱和预测器的第一位就是预测结果
}
