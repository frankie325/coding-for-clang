#include <iostream>

using namespace std;

// 引用传递
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(a, b);
    cout << "a=" << a << endl; // 20
    cout << "b=" << b << endl; // 10
    return 0;
}