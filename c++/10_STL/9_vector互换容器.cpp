#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> &v)
{

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
/*
功能描述：

实现两个容器内元素进行互换
函数原型：

swap(vec); // 将vec与本身的元素互换
*/

void test()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v的容量为：" << v.capacity() << endl; // 131072
    cout << "v的大小为：" << v.size() << endl;     // 100000

    v.resize(3);
    // 改变容器大下后，容量还是很大
    cout << "v的容量为：" << v.capacity() << endl; // 131072
    cout << "v的大小为：" << v.size() << endl;     // 3

    // 可以用swap收缩内存
    // vector<int>(v)为匿名对象，交换完容器后，匿名对象指向131072大的内存，执行完代码后该内存会被立即回收
    vector<int>(v).swap(v);
    cout << "v的容量为：" << v.capacity() << endl; // 3
    cout << "v的大小为：" << v.size() << endl;     // 3
}

int main()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    // 互换容器
    cout << "互换后" << endl;

    v1.swap(v2);
    printVector(v1);
    printVector(v2);

    test();
}