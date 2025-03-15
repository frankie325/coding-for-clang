#include <iostream>
using namespace std;

class Person
{
public:
    // 友元：让运算重载可以访问私有成员变量
    friend ostream &operator<<(ostream &cout, Person &p);
    Person()
    {
        m_a = 10;
        m_b = 10;
    }

private:
    // 利用成员函数重载 左移运算符 p.operator<<(cout) 简化版本 p<<cout （这里p在左边，是不对的）
    // 因此不会利用成员函数重载<<运算符，无法实现cout在左侧
    // void operator<<(cout)
    // {
    // }
    int m_a;
    int m_b;
};

// 只能利用全局函数重载左移运算符
ostream &operator<<(ostream &cout, Person &p) // 本质： operator<<(cout,p)简化为 cout << p
{
    cout << "m_a = " << p.m_a << endl;
    cout << "m_b = " << p.m_b << endl;
    return cout; // 返回cout支持链式调用 如：cout << p << endl;
};

int main()
{
    Person p;
    // p.m_a = 10;
    // p.m_b = 10;

    // cout << p.m_a << endl;
    cout << p << endl;
    return 0;
}