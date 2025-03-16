#include <iostream>
#include <deque>
using namespace std;
void printDeque(const deque<int> &d)
{
    // const_iterator表示，容器中的数据不可修改
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        // *it = 100; //error
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

    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << "front:" << d.front() << endl;

    cout << "back:" << d.back() << endl;
    return 0;
}