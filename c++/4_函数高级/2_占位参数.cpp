#include <iostream>

using namespace std;

// 函数占位参数，占位参数可以有默认参数
// 占位参数后面还会讲到，在这里意义不大
void func(int a, int)
{
    cout << "this is func" << endl;
}
int main()
{
    func(10, 10); // 占位参数必须填补
}