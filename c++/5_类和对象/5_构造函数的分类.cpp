#include <iostream>
using namespace std;

class Person
{
public:
    int age;

    /*
    构造函数的分类及调用
    分类：
    按照参数分类：无参构造 和 有参构造
    按照类型分类：普通构造 和 拷贝构造函数
    */
    Person()
    {
        cout << "Person无参构造的调用" << endl;
    };
    // 有参构造
    Person(int a)
    {
        age = a;
        cout << "Person有参构造的调用" << endl;
    };

    // 拷贝构造函数：将同类对象传入，使用const引用，因为不能随意修改传入的对象
    Person(const Person &p)
    {

        // 将年龄拷贝
        age = p.age;
        cout << "Person拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }
};

int main()
{
    // 调用方式：三种
    // *1、括号法
    Person p1;     // 默认构造函数调用
    Person p2(10); // 有参构造函数调用
    Person p3(p2); // 拷贝构造函数调用
    cout << "p2的年龄是：" << p2.age << endl;
    cout << "p3的年龄是：" << p3.age << endl;

    // !注意：使用默认构造函数时，不要加();
    // 因为下面这行代码，编译器会认为是一个函数声明 例如：void func()
    // Person p1();

    // *2、显示法
    Person p4;
    Person p5 = Person(10); // 有参构造
    Person p6 = Person(p5); // 拷贝构造

    Person(10); //匿名对象 特点：当前执行结束后，系统会立即回收掉匿名对象
    // aaa输出之前，匿名对象就已经销毁
    cout << "aaa" << endl;

    // !注意：不要利用拷贝构造函数初始化匿名对象
    // 编译器会认为Person(p3)等价于Person p3，p3在上面已经定义过了
    // Person(p3); //error

    // *3、隐式转换法
    Person p7 = 100; // 相当于写了Person p7 = Person(100)，编译器会自动转换
    Person p8 = p7;  // 拷贝构造
    return 0;
}