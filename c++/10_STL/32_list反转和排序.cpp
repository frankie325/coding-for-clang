#include <iostream>
#include <list>
using namespace std;

void printlist(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
/*
函数原型：

reverse(); //反转链表
sort(); //链表排序
*/

bool myCompare(int val, int val2)
{
    return val > val2;
}

int main()
{
    list<int> l;
    l.push_back(90);
    l.push_back(30);
    l.push_back(20);
    l.push_back(70);
    printlist(l);

    // 反转容器的元素
    l.reverse();
    printlist(l);

    // 所有不支持随机访问迭代器的容器，不可以用标准算法
    // 不支持随机访问迭代器的容器，内部会返回对应一些算法
    // 排序
    l.sort(); // 默认的排序规则 从小到大
    printlist(l);

    l.sort(myCompare); // 指定规则，从大到小
    printlist(l);
    return 0;
}