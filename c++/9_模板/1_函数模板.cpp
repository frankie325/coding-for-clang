#include <iostream>
using namespace std;

/*
template<typename T>
函数声明或定义
*/

// 利用模板提供通用的交换函数
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void func()
{
    cout << "func 调用" << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    // 利用模板实现交换
    // 1、自动类型推导
    // mySwap(a, b);

    // 2、显示指定类型
    mySwap<int>(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // !注意：1、自动类型推导，必须推导出一致的数据类型T,才可以使用
    char c = 'c';
    // mySwap(a, c); // error

    // !注意：2、模板必须要确定出T的数据类型，才可以使用
    // func();      // error，模板不能独立使用，必须确定出T的类型
    func<int>(); // 利用显示指定类型的方式，给T一个类型，才可以使用该模板
    return 0;
}