#include <iostream>
using namespace std;

/*
 浅拷贝：简单的赋值引用操作
 深拷贝：在堆区重新申请空间，进行拷贝操作
*/

class Person
{
public:
    int age;
    int *height; // 将身高的数据开辟到堆区
    Person()
    {
        cout << "Person无参构造的调用" << endl;
    };

    Person(int a, int h)
    {
        age = a;
        height = new int(h); // 在堆区开辟空间
        cout << "Person有参构造的调用" << endl;
    };

    // *自己实现拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person &p)
    {
        age = p.age;
        // height = p.height; //在默认拷贝构造函数中，编译器是这么操作指针的，两个对象.height都指向同一块地址
        height = new int(*p.height); // 深拷贝操作，重新开辟一块内存
        cout << "Person拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        // 将堆区开辟的数据做释放操作
        // !error：导致在析构函数中就会重复释放内存空间，导致错误
        // 自己实现拷贝构造函数后就不会报错了
        if (height != NULL)
        {
            delete height;
            height = NULL;
        }
        cout << "Person析构函数的调用" << endl;
    }
};

int main()
{
    Person p1(20, 160);
    cout << "p1的年龄为：" << p1.age << "身高为：" << *p1.height << endl;

    Person p2(p1);
    cout << "p1的年龄为：" << p2.age << "身高为：" << *p2.height << endl;

    return 0;
}