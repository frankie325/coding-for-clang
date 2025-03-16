#include <iostream>
#include <map>
using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}
/*
函数原型：

insert(elem); //在容器中插入元素。
clear(); //清除所有元素
erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(key); //删除容器中值为key的元素
*/

int main()
{
    // 插入
    map<int, int> m;
    // 第一种插入方式
    m.insert(pair<int, int>(1, 10));
    // 第二种插入方式
    m.insert(make_pair(2, 20));
    // 第三种插入方式
    m.insert(map<int, int>::value_type(3, 30));
    // 第四种插入方式
    m[4] = 40;
    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3);
    printMap(m);

    // 清空
    m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);
    return 0;
}