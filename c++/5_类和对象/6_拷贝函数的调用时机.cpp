#include <iostream>
using namespace std;

class Person
{
public:
    int age;
    Person()
    {
        cout << "Person无参构造的调用" << endl;
    };
    Person(int a)
    {
        age = a;
        cout << "Person有参构造的调用" << endl;
    };

    Person(const Person &p)
    {
        age = p.age;
        cout << "Person拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }
};

// 值传递的方式给函数传参，相当于拷贝一个副本给形参
void doWork(Person p)
{
    p.age = 100; // 不影响实参的值
}

// 值方式返回局部对象，也是相当于返回一个拷贝副本
Person doWork2()
{

    Person p;
    cout << (int *)&p << endl;
    return p; // 局部变量已经被销毁了
}

int main()
{
    // 1、使用一个已经创建完毕的对象来初始化一个新对象
    // Person p1(20);
    // Person p2(p1);

    // 2、值传递的方式给函数传参
    // doWork(p1);
    // 3、值方式返回局部对象
    Person p3 = doWork2();
    cout << (int *)&p3 << endl;
    /*
     *P3 对象的地址和 doWork2() 中 P 对象的地址不一定会相同。
     *在你看到地址相同的情况下，这很可能是因为编译器的优化行为，
     *称为"返回值优化"(RVO - Return Value Optimization)。
     */

    return 0;
}