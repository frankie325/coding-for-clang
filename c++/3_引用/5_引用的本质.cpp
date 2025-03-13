#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    // *引用的本质就是一个指针常量，引用一旦初始化后，就不可以发生改变
    // 自动转换为int * const ref = &a;指针常量的指向不可改，也说明为什么引用不可更改
    int &ref = a;
    ref = 20; // 内部发现ref是引用，自动帮我们转换为 *ref = 20;

    cout << "a=" << a << endl;
    cout << "ref=" << ref << endl;
    return 0;
}