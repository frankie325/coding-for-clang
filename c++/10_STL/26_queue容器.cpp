#include <iostream>
#include <queue>
using namespace std;
/*
构造函数：
    queue<T> que; //queue采用模板类实现，queue对象的默认构造形式
    queue(const queue &que); //拷贝构造函数
赋值操作：
    queue& operator=(const queue &que); //重载等号操作符
数据存取：
    push(elem); //往队尾添加元素
    pop(); //从队头移除第一个元素
    back(); //返回最后一个元素
    front();  //返回第一个元素
大小操作：
    empty(); //判断堆栈是否为空
    size();  //返回栈的大小
*/

int main()
{
    // 创建队列
    queue<int> q;

    // 向队列中添加元素  入队操作
    q.push(10);
    q.push(20);
    q.push(30);

    // 队列不提供迭代器，更不支持随机访问
    while (!q.empty())
    {
        // 输出队头元素
        cout << "队头元素为： " << q.front() << endl;
        // 输出队尾元素
        cout << "队尾元素为： " << q.back() << endl;
        // 弹出队头元素
        q.pop();
    }

    cout << "队列大小为：" << q.size() << endl;
    return 0;
}