#include <iostream>
using namespace std;

class Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Base -func调用" << endl;
    }

    // 重载函数会被隐藏
    static void func(int a)
    {
        cout << "Base -带参数func调用" << endl;
    }
};

int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Son -func调用" << endl;
    }
};
int Son::m_A = 200;

int main()
{
    // 同名静态成员属性
    // *1. 通过对象访问
    Son s;
    cout << "Son下m_A= " << s.m_A << endl;
    // 加作用域，可以访问Base中的静态属性
    cout << "Base下m_A= " << s.Base::m_A << endl;

    // *2. 通过类名访问
    cout << "Son下m_A= " << Son::m_A << endl;
    cout << "Base下m_A= " << Base::m_A << endl;
    // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
    cout << "Base下m_A= " << Son::Base::m_A << endl;

    // 同名静态成员函数
    // *1. 通过对象访问
    s.func();
    s.Base::func();

    // *2. 通过类名访问
    Son::func();
    Son::Base::func();
    // 如果想访问父类被隐藏的同名成员，需要加作用域
    Son::Base::func(100);
    return 0;
}