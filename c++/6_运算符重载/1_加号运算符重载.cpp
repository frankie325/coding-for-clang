#include <iostream>
using namespace std;

// 运算符重载：对已有的运算符重新定义，赋予其另一种功能，以适应不同的数据类型
class Person
{

public:
    // *1.成员函数重载+号
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;
        return temp;
    }

    // 运算符重载也可以函数重载
    Person operator+(int num)
    {
        Person temp;
        temp.m_a = this->m_a + num;
        temp.m_b = this->m_b + num;
        return temp;
    }

    int m_a;
    int m_b;
};

// *2.全局函数重载+号
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_b + p2.m_b;
    return temp;
}

int main()
{
    Person p1;
    p1.m_a = 10;
    p1.m_b = 10;

    Person p2;
    p2.m_a = 10;
    p2.m_b = 10;

    // 希望：p1加p2生成的p3
    // p3的成员属性可以是p1和p2成员属性的加和
    // Person p3 = p1 + p2;
    // Person p3 = p1.operator+(p2); //*成员函数重载的本质调用
    Person p3 = operator+(p1, p2); //*全局函数重载的本质调用
    cout << p3.m_a << endl;        // 20
    cout << p3.m_b << endl;        // 20

    // * 运算符重载，也可以发生函数重载
    Person p4 = p1 + 100;   // Person + int类型
    cout << p4.m_a << endl; // 110
    cout << p4.m_b << endl; // 110
}