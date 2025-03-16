#include <iostream>
using namespace std;

/*
建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
语法：
template<typename T>
类
*/
template <typename NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }

public:
    NameType mName;
    AgeType mAge;
};
int main()
{
    // 指定NameType 为string类型，AgeType 为 int类型
    Person<string, int> p1("孙悟空", 999);
    p1.showPerson();

    /*
    类模板与函数模板区别主要有两点：
        1.类模板没有自动类型推导的使用方式
        2.类模板在模板参数列表中可以有默认参数
    */
    // Person p2("孙悟空", 1000); // error 类模板使用时候，不可以用自动类型推导
    Person<string, int> p2("孙悟空", 1000); // 必须使用显示指定类型的方式，使用类模板
    p2.showPerson();

    // 默认参数:
    Person<string> p3("猪八戒", 999); // 类模板中的模板参数列表 可以指定默认参数
    p3.showPerson();
    return 0;
}