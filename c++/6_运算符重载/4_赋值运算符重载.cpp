#include <iostream>
using namespace std;

class Person
{
public:
    int *m_age;

    Person(int age)
    {
        m_age = new int(age);
    }

    ~Person()
    {
        // 2. 在析构函数中就会对同一个地址释放两次
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
    }

    // *赋值运算重载：
    Person &operator=(Person &p)
    {
        // 编译器提供的是浅拷贝
        // m_age = p.m_age

        // 应该先判断是否有属性在堆区，如果有先释放干净，再深拷贝
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
        m_age = new int(*p.m_age);

        return *this;
    }
};

int main()
{
    Person p1(18);
    Person p2(20);
    p2 = p1; // 1. 赋值操作，指针是浅拷贝，导致p1.m_age指针和p2.m_age指向同一块地址

    Person p3(30);
    p3 = p2 = p1;
    cout << "p1的年龄为：" << *p1.m_age << endl;
    cout << "p2的年龄为：" << *p2.m_age << endl;
    cout << "p3的年龄为：" << *p3.m_age << endl;
}