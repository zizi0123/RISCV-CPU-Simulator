#include "main.h"



int main() {
    freopen("../testcases/tak.data", "r", stdin);
//    freopen("ans.out", "w", stdout);
    Memory memory;
    RegisterFile RF;
    ReorderBuffer RoB;
    ReservationStation RS;
    Predictor predictor;
    std::random_device rd;
    std::mt19937 rng(rd());
    memory.Loadin(); //载入所有内存中的数据
    int a[5] = {0,1,2,3,4};
    while (true) { //执行到某语句会结束循环并且返回
        std::shuffle(a,a+4,rng); //使用shuffle随机打乱来模拟并行
        for(auto &i:a){
            if(i == 0){
                FetchAndDecode(RoB,predictor,memory,RS,RF);
            }else if (i == 1){
                Issue(RoB,RS,RF);
            }else if (i == 2){
                Execute(RS,RoB,memory);
            }else if (i == 3){
                WriteBack(RS,RoB);
            }else{
                Commit(RoB,memory,RF,predictor,RS);
            }
        }
        RF.Flush();

        if (RoB.program_finish) {
            std::cout << (((unsigned int) RF.GetValue(10)) & 255)<<'\n';
            std::cout<<"branch instruction num: "<<predictor.total_num()<<' '<<"prediction accuracy: "<<predictor.PreAccuracy();
            return 0;
        }
    }
}