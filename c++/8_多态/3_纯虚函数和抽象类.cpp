#include <iostream>
using namespace std;

// 在多态中，通常父类中的虚函数实现是毫无意义的，主要都是调用子类重写的内容，因此可以将虚函数定义为纯虚函数
class Base
{
public:
    // 纯虚函数
    // 只要有一个纯虚函数，这个类成为抽象类
    // 抽象类特点：
    // 1、无法实例化对象
    // 2、抽象类的子类，必须要重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
public:
    virtual void func()
    {
        cout << "fuc函数调用" << endl;
    }
};

int main()
{
    // 无法实例化抽象类
    // Base b;   // error
    // new Base; // error

    Base *b = new Son;
    b->func();
    return 0;
}