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

size();  //返回容器中元素的个数

empty();  //判断容器是否为空

resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
​ //如果容器变短，则末尾超出容器长度的元素被删除。

resize(num, elem);  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
*/

int main()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    if (l1.empty())
    {
        cout << "l1为空" << endl;
    }
    else
    {
        cout << "l1不为空" << endl;
        cout << "l1的大小为： " << l1.size() << endl;
    }

    // 重新指定大小
    l1.resize(10);
    printlist(l1);

    l1.resize(2);
    printlist(l1);
    return 0;
}