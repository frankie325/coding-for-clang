#include <iostream>
#include <map>
using namespace std;

/*
学习目标：
    map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
主要技术点:
    利用仿函数，可以改变排序规则
*/

class MyCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

int main()
{
    // 默认从小到大排序
    // 利用仿函数实现从大到小排序
    map<int, int, MyCompare> m;

    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key:" << it->first << " value:" << it->second << endl;
    }
    return 0;
}