#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base下的函数调用" << endl;
    }

    void func(int a)
    {
        cout << "Base下的函数调用a" << endl;
    }
};

class Son : public Base
{
public:
    int m_A;
    Son()
    {
        m_A = 200;
    }

    void func()
    {
        cout << "Son下的函数调用" << endl;
    }
};

int main()
{
    Son s;
    cout << "Son下的m_A = " << s.m_A << endl;
    // 如果通过子类对象 访问到父类中的同名成员，需要加作用域
    cout << "Base下的m_A = " << s.Base::m_A << endl;
 
    s.func(); // 直接调用，调用的是子类中的同名成员
    // 调用父类中同名成员函数，加作用域
    s.Base::func();

    // !如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数，包括重载函数
    // 如果需要访问父类中被隐藏的同名成员函数，需要加作用域
    // s.func(100); // error 调用父类重载函数
    s.Base::func(100);

    return 0;
}