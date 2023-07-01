#ifndef RISC_V_REGISTERFILE_H
#define RISC_V_REGISTERFILE_H

struct RegisterElement{
    int depend= -1; //-1表示无依赖
    int value;

    RegisterElement() = default;

    explicit RegisterElement(const int &num);
};

class RegisterFile{
private:
    RegisterElement regs_old[32];
    RegisterElement regs_new[32];
public:
    void SetDep(const int&reg_num,const int &ins_num);

    void SetValue(const int&reg_num,const int &value);

    int GetDep(const int &reg_num) const;

    int GetValue(const int&reg_num) const;

    void Flush();

    RegisterFile();

    //branch指令预判错误,清除所有的依赖关系
    void Clear();
};

#endif
