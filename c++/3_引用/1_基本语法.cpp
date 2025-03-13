#include <iostream>

using namespace std;

/*
!引用与c语言的取地址符没有半毛钱关系
引用基本语法
数据类型 &别名 = 原名
*/

int main()
{
    int a = 10;
    int &b = a;
    // a和b地址都是一样
    cout << "a地址= " << &a << endl;
    cout << "b地址= " << &b << endl;
    b = 12; // 操作的是同一块内存
    cout << "a的值改变了：" << a << endl;
}