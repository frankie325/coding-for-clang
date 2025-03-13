#include <iostream>

using namespace std;

/*

1.引用必须初始化
int &b; //错误
2.引用初始化后不可以改变
int c = 20;
b = c //引用在初始化后，不可以改变，还是和a共享同一块地址，相当于赋值操作
*/

int main()
{
    int a = 10;
    // 引用必须初始化
    int &b = a;

    int c = 20;
    b = c;                       // 这是赋值操作，而不是更改引用
    cout << "a = " << a << endl; // 20
    cout << "b = " << b << endl; // 20
    cout << "c = " << c << endl; // 20
}