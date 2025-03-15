#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base构造函数" << endl;
    }

    ~Base()
    {
        cout << "Base析构函数" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son构造函数" << endl;
    }

    ~Son()
    {
        cout << "Son析构函数" << endl;
    }
};

int main()
{
    /*
    输出：看成入栈和出栈
        Base构造函数
        Son构造函数
        Son析构函数
        Base析构函数
    */
    Son s;
    return 0;
}