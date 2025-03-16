#include <iostream>
#include <string>
using namespace std;

class Calculate
{
public:
    int num1; // 操作数1
    int num2; // 操作数2

    int getResult(string oper)
    {
        if (oper == "+")
        {
            return num1 + num2;
        }
        else if (oper == "-")
        {
            return num1 - num2;
        }
        else if (oper == "*")
        {
            return num1 * num2;
        }
        else if (oper == "/")
        {
            return num1 / num2;
        }
        // 如果想扩展新的功能，需要修改源码
        // 在真实开发中，提倡开闭原则
        return 0;
    }
};

// *利用多态实现计算器
// 1、组织结构性强
// 2、可读性强

// 实现计算器抽象类
class AbstractCalculator
{
public:
    int num1; // 操作数1
    int num2; // 操作数2
    // 定义成虚函数
    virtual int getResult()
    {
        return 0;
    }
};

// 加法计算器类
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 + num2;
    }
};

// 减法计算器类
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 - num2;
    }
};

// 乘法计算器类
class MultiCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 * num2;
    }
};

int main()
{
    AbstractCalculator *cal = new AddCalculator;
    cal->num1 = 10;
    cal->num2 = 10;

    cout << cal->num1 << "+" << cal->num2 << "=" << cal->getResult() << endl;
    delete cal;
    return 0;
}