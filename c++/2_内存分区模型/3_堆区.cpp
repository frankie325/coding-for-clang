#include <iostream>
using namespace std;

// 1、new的基本写法
int *func()
{
    // 利用new关键字，可以将数据开辟到堆区
    // 创建一个整型数据，初始化为10，返回新开辟的内存地址给指针p
    int *p = new int(10);
    return p;
}

// 2、在堆区利用new开辟数组
void test()
{
    int *arr = new int[10]; // 10代表数组有10个元素,并把数组首元素地址返回给arr指针

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    // 释放堆区数组
    // 释放数组的时候，要加一个[]才可以
    delete[] arr;
}

int main()
{
    // 在堆区创建数据，堆区的数据由程序员管理
    int *p = func();
    cout << *p << endl; // 10
    cout << *p << endl; // 10
    // 如果想释放堆区的数据，利用关键词delete
    delete p;
    cout << *p << endl; // 0

    test();
    return 0;
}