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
功能描述：
    创建list容器
函数原型：
    list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
    list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
    list(n,elem); //构造函数将n个elem拷贝给本身。
    list(const list &lst); //拷贝构造函数
*/

int main()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    printlist(l1);

    list<int> l2(l1.begin(), l1.end());
    printlist(l2);

    list<int> l3(l2);
    printlist(l3);

    list<int> l4(10, 1000);
    printlist(l4);
}