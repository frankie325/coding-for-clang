#include <iostream>

using namespace std;

void showValue(const int &val)
{
    // val = 1000; // 不能修改，防止误操作
    cout << "val=" << val << endl;
}

int main()
{
    // 常量引用
    // 使用场景：用来修饰形参，防止误操作

    int a = 10;
    // int &ref = 10; //error 引用必须引一块合法的内存空间
    // *加上const之后 编译器将代码修改为 int temp = 10; const int & ref = temp;
    const int &ref = 10;
    // ref = 20; // 加入const之后变为只读，不可以修改

    showValue(a);
    return 0;
}