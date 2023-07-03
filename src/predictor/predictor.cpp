#include "predictor.h"

bool Predictor::predict(const int &address) {
    std::bitset<2> history = BHT[address & 1023];
    unsigned int num = ((address & 1023) << 2) + history.to_ulong();
    std::bitset<2> saturation_counter = PHT[num];
    return saturation_counter.test(1); //二位饱和预测器的第一位就是预测结果
}

void Predictor::AddWrong() {
    ++wrong_num;
}

void Predictor::AddRight() {
    ++right_num;
}

double Predictor::PreAccuracy() {
    return (double) (right_num) / (double) (right_num + wrong_num);
}

int Predictor::total_num() {
    return right_num + wrong_num;
}
