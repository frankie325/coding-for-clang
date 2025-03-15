#include <iostream>
using namespace std;

/*
 !如果用户定义有参构造函数，c++默认不提供默认无参构造，但是会提供默认拷贝构造
 !如果用户定义拷贝构造函数，c++不会再提供其它构造函数

 创建一个类，c++编译器会给每个类添加至少三个函数
 默认构造（空实现）
 析构函数（空实现）
 拷贝构造（值拷贝）
*/

class Person
{
public:
    int age;
    // Person()
    // {
    //     cout << "Person无参构造的调用" << endl;
    // };
    Person(int a)
    {
        age = a;
        cout << "Person有参构造的调用" << endl;
    };

    // *编译器会默认提供拷贝构造，将传入的对象p的属性全部拷贝过来
    // Person(const Person &p)
    // {
    //     age = p.age;
    //     cout << "Person拷贝构造函数调用" << endl;
    // }

    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }
};

int main()
{
    Person p1(20);
    Person p2(p1);

    cout << "p1的年龄为：" << p1.age << endl;
    cout << "p2的年龄为：" << p2.age << endl;

    // Person p3; //error 因为定义了有参构造函数，编译器不再提供默认构造
    return 0;
}