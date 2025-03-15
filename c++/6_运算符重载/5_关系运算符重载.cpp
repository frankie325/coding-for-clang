#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string m_name;
    int m_age;
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

    // 重载==关系运算符
    bool operator==(Person &p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name)
        {
            return true;
        }
        return false;
    }
    // 重载!=关系运算符
    bool operator!=(Person &p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    Person p3("Jack", 20);

    if (p1 == p2)
    {
        cout << "p1和p2相等" << endl;
    }

    if (p1 != p3)
    {
        cout << "p1和p3不相等" << endl;
    }
}