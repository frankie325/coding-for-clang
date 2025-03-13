#include <iostream>
using namespace std;
// !栈区注意事项：不要返回局部变量的地址
int *func(int b) // 形参数据也会放在栈区
{
    int a = 10; // 局部变量，存放在栈区，栈区的数据在函数执行完后自动释放内存
    return &a;  // 返回局部变量的地址
}

int main()
{
    int *p = func(10);
    cout << *p << endl; // 第一次可以打印正确的数字，是因为编译器做了保留
    cout << *p << endl; // 第二次这个数据就不再保留了
    return 0;
}