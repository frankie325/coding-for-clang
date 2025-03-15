#include <iostream>
#include <string>
using namespace std;

class myPrint
{
public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};

// 仿函数非常灵活，没有固定写法
class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

int main()
{
    myPrint myprint;
    // 由于使用起来非常类似于函数调用，因此称为仿函数
    myprint("hello world");

    MyAdd myadd;
    int ref = myadd(100, 200);
    cout << "ref = " << ref << endl;

    // 匿名函数对象，执行完立即释放
    cout << MyAdd()(100, 100) << endl;
    return 0;
}