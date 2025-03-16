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
函数原型：

at(int idx);  //返回索引idx所指的数据
operator[];  //返回索引idx所指的数据
front();  //返回容器中第一个数据元素
back(); //返回容器中最后一个数据元素
*/

int main()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        // 利用中括号来访问元素
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << "v1的第一个元素为： " << v1.front() << endl;
    cout << "v1的最后一个元素为： " << v1.back() << endl;
    return 0;
}