#include <iostream>
using namespace std;

class Person
{
public:
    int age;
    // 1、解决名称冲突
    Person(int age)
    {
        // 形参age与成员age变量名一样
        // age = age;
        // *this指针指向被调用的成员函数所属的对象
        this->age = age;
    }

    // 2、返回对象本身用*this
    // !注意：如果是Person add(int age) 值返回，则返回的是拷贝
    // Person add(int age)
    Person &add(int age)
    {
        this->age += age;
        // *this指向实例的指针，而*this指向的就是实例本体
        return *this;
    }
};

int main()
{
    Person p1(10);
    cout << "p1的年龄为：" << p1.age << endl; // 10
    p1.add(1).add(1).add(1);                  // 链式调用
    cout << "p1的年龄为：" << p1.age << endl; // 13，值拷贝返回则输出11
    return 0;
}