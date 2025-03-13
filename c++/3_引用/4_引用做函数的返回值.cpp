#include <iostream>

using namespace std;

// 引用做函数的返回值
// 1、不要返回局部变量的引用

int &test1()
{
    int a = 10; // 局部变量存放在栈区
    return a;
}

// 2、函数的调用可以作为左值
int &test2()
{
    static int a = 10; // 静态变量，存放在全局区
    return a;
}
int main()
{
    int &ref1 = test1();               // 返回值内存已经释放
    cout << "ref1 = " << ref1 << endl; // 输出错误
    int &ref2 = test2();
    cout << "ref2 = " << ref2 << endl; // 10
    cout << "ref2 = " << ref2 << endl; // 10
    // *如果函数的返回值是引用，函数的调用可以作为左值
    test2() = 1000;
    cout << "ref2 = " << ref2 << endl; // 1000
    return 0;
}