#include <iostream>
using namespace std;

class Person
{
    // *静态成员变量、函数也有访问权限
private:
    static int m_B;

public:
    // *静态成员变量：
    // 1.所有对象共享同一份数据
    // 2.编译阶段就分配内存
    // 3.类内声明，类外初始化操作
    static int m_A;

    int m_C;
    // *静态成员函数
    // 1.所有对象共享同一个函数
    // 2.静态成员函数只能访问静态成员变量
    static void func()
    {
        m_A = 100;
        // m_C = 300; //error 不可以访问非静态成员变量
        cout << "静态成员函数调用" << endl;
    }

    // 非静态成员变量：属于类的实例上
    int a;
    // 静态成员变量：不属于类的实例上
    static int b;
    // 非静态成员函数：不属于类的实例上
    void c() {}
    // 静态成员函数：不属于类的实例上
    static void d() {}
};

int Person::m_A = 100; // 类外初始化操作

int main()
{
    // cout << p1.m_B << endl; //error
    // cout << Person::m_B << endl; // error

    Person p1;
    cout << p1.m_A << endl; // 100

    Person p2;
    p2.m_A = 200;
    // 静态成员变量，不属于某个对象上，所有对象都共享同一份数据
    cout << p2.m_A << endl; // 200

    // *通过类名进行访问
    cout << Person::m_A << endl; // 200

    p1.func();
    Person::func();
}