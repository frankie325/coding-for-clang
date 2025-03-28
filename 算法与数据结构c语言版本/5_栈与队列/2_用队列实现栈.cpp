#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
一个队列在模拟栈弹出元素的时候只要将队列头部的元素（除了最后一个元素外）
 重新添加到队列尾部，此时再去弹出元素就是栈的顺序了。
*/
class MyStack
{
public:
    queue<int> que;

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        int size = que.size();
        size--;
        while (size--) // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
        {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    int top()
    {
        int size = que.size();
        size--;
        while (size--) // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
        {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.push(result);         // 将获取完的元素也重新添加到队列尾部，保证数据结构没有变化
        que.pop();
        return result;
    }

    int empty()
    {
        return que.empty();
    }
}