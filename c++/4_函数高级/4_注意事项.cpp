#include <iostream>

using namespace std;

// !注意事项
// *1、引用作为重载条件
void func1(int &a)
{
    cout << "func(int & a) 的调用" << endl;
}

void func1(const int &a)
{
    cout << "func(const int &a)的调用" << endl;
}

// *2、函数重载碰到默认参数
void func2(int a, int b = 10)
{
    cout << "func(int a, int b = 10)的调用" << endl;
}

void func2(int a)
{
    cout << "func(int a)的调用" << endl;
}

int main()
{
    int a = 10;
    func1(a);  // 调用无const
    func1(10); // 调用有const，常量引用

    func2(10);     // error，碰到默认参数，产生二义性，编译器不知道走的是哪个函数
    func2(10, 20); // 传递两个参数，编译器就知道走哪
    return 0;
}