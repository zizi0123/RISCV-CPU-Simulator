struct RegisterElement{
    int depend= -1;
    int ins_num;

    RegisterElement() = default;

    explicit RegisterElement(const int &num,const bool& dep=false);
};

class RegisterFile{
public:
    RegisterElement regs[32];

    RegisterFile();

    //去除依赖关系
    void ClearDep(int reg_num);

    //添加依赖关系
    void AddDep(int reg_num,int entry_num);

    //branch指令预判错误
    void Clear();
};