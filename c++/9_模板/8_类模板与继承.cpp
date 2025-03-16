#include <iostream>
#include <string>
using namespace std;

/*
当类模板碰到继承时，需要注意一下几点：
    当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
    如果不指定，编译器无法给子类分配内存
    如果想灵活指定出父类中T的类型，子类也需变为类模板
*/
template <class T>
class Base
{
    T m;
};

// class Son : public Base // 错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son : public Base<int>
{
};

// 类模板继承类模板 ,可以用T2指定父类中的T类型
template <class T1, class T2>
class Son2 : public Base<T2> // 传入T2指定父类中的T类型
{
public:
    Son2()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
};

int main()
{
    Son c;

    Son2<int, char> son2;
}