#include <iostream>
using namespace std;
// 1、如果某个位置参数有默认值，那么从这个位置往后，都必须要有默认值
// int add(int a, int b = 10, int c)
// {
//     return a + b + c;
// }

// 2、声明和实现只能有一个有默认参数
// int add(int a, int b = 20, int c = 20); //error
int add(int, int, int);
int add(int a, int b = 10, int c = 10)
{
    return a + b + c;
}

int main()
{
    // int sum = add(1, 2, 3);
    int sum = add(10);
    cout << "sum=" << sum << endl;
}
