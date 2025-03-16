#include <iostream>
using namespace std;

/*
1. 静态多态（编译时多态）
静态多态是在编译时期就确定函数调用的多态行为，主要通过：

    函数重载
    运算符重载
    模板

2. 动态多态（运行时多态）
动态多态是在运行时期才确定函数调用的多态行为，通过：

    虚函数
    继承
    父类指针或引用指向子类对象

*/

// 动物类
class Animal
{

public:
    // 函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

// 猫类
class Cat : public Animal
{

public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};
// 地址早绑定，在编译阶段确定函数地址
// 如果想要让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定

// 动态多态满足条件
// 1.有继承关系
// 2.子类要重写父类的虚函数

// 动态多态的使用
// 父类的引用或者指针 指向子类对象
void doSpeak(Animal &animal) // Animal &animal = cat;
{
    animal.speak(); // 执行的是动物在说话
};

int main()
{
    Cat cat;
    doSpeak(cat);
    return 0;
}