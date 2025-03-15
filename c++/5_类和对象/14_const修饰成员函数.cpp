#include <iostream>
using namespace std;

class Person
{
public:
    int m_a;
    mutable int m_b; // mutable表示这个变量即使在常函数中也可以修改
    Person()
    {
        // !this指针的本质 是指针常量，指针的指向是不可以修改的
        // this = NULL; // error
    }

    // *在成员函数后面加const，修饰的是this指向，让指针指向的值也可以不修改
    // 相当于const Person * const this
    void showPerson() const
    {
        // this->m_a = 100; // error
        this->m_b = 200;
    }

    void func()
    {
    }
};

int main()
{
    Person p1;
    p1.showPerson();

    const Person p2; // 常对象
    // p2.m_a = 30;     // error 常对象不可以修改普通属性
    p2.m_b = 300;    // 常对象下也可以修改m_b
    p2.showPerson(); // 常对象可以调用常成员函数
    // p2.func(); //error 常对象不可以调用普通的成员函数，因为普通成员函数可以修改属性
}