#include <iostream>
#include <deque>
#include <algorithm>
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
功能描述：
    利用算法实现对deque容器进行排序
算法：
    sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
*/

int main()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    printDeque(d);

    // 默认从小到大排序
    sort(d.begin(), d.end());
    printDeque(d);
    return 0;
}