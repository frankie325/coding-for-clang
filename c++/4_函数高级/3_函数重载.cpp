#include <iostream>

using namespace std;

// 函数重载
// 可以让函数名相同，提高复用性

// 函数重载满足条件
// 1、同一个作用域下
// 2、函数名称相同
// 3、函数参数类型不同，或者个数不同，或者顺序不同

void func()
{
    cout << "func 的调用" << endl;
}

void func(int a)
{
    cout << "func(int a)的调用" << endl;
}

void func(int a, double b)
{
    cout << "func(int a, double b)的调用" << endl;
}

void func(double a, int b)
{
    cout << "func(double a, int a)的调用" << endl;
}

// !注意事项，函数的返回值不可以作为函数重载的条件
// 因为可以不接收函数调用的返回值，会产生二义性
// int func(double a, int b)
// {
//     cout << "int func(double b, int a)的调用" << endl;
// }

int main()
{
    func();
    func(1); // 传递参数不同
    func(1, 3.14);
    func(3.14, 1); // 传递参数顺序不同
    return 0;
}