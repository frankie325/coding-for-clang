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

push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
函数原型：

front(); //返回第一个元素。
back(); //返回最后一个元素。
*/

int main()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    // cout << l1.at(0) << endl;//错误 不支持at访问数据
    // cout << l1[0] << endl; //错误  不支持[]方式访问数据
    cout << "第一个元素为： " << l1.front() << endl;
    cout << "最后一个元素为： " << l1.back() << endl;

    // list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = l1.begin();
    // it = it + 1;//错误，不可以跳跃访问，即使是+1
    return 0;
}