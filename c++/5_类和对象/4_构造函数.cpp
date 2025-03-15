#include <iostream>
using namespace std;

class Person
{
public:
    /*
        构造函数：
        没有返回值，不用写void
        函数名与类名相同
        构造函数可以有参数，可以发生重载
        创建对象时，构造函数会自动调用，而且只调用一次
    */
    Person()
    {
        cout << "Person构造函数的调用" << endl;
    };

    /*
        析构函数：进行清理的操作
        没有返回值，不用写void
        函数名与类名相同，在名称前加~
        析构函数不可以有参数，不可以发生重载
        对象在销毁前，会自动调用析构函数，而且只会调用一次
    */
    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }
};

int main()
{
    Person p; // 在栈上的数据，执行完毕后，释放这个对象

    return 0;
}