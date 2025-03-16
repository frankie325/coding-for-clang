#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
功能描述：

减少vector在动态扩展容量时的扩展次数
函数原型：

reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/

void test()
{
    vector<int> v;

    // 利用预留空间
    // *如果用reserve设置预留空间，此时num等于1，不需要再为vector动态开辟内存空间
    v.reserve(100000);

    int num = 0; // 统计开辟次数
    int *p = NULL;

    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        // p如果不等于vector首地址
        if (p != &v[0])
        {
            // 则设置为首地址
            p = &v[0];
            // 统计vector内存开辟次数
            num++;
        }
    }

    cout << "num:" << num << endl; // 重新开辟了18次内存空间
}

int main()
{
    test();
    return 0;
}