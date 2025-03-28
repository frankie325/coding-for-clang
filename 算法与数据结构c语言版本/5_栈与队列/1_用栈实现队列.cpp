#include <iostream>
#include <stack>
using namespace std;

/*
使用栈来模拟队列的行为，如果仅仅用一个栈，是一定不行的，
所以需要两个栈一个输入栈，一个输出栈，这里要注意输入栈和输出栈的关系。
*/
class MyQueue
{
public:
    stack<int> stIn;
    stack<int> stOut;

    void push(int x)
    {
        stIn.push(x);
    }

    void pop()
    {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty())
        {
            // 从stIn导入数据直到stIn为空
            while (!stIn.empty())
            {
                int temp = stIn.top();
                stIn.pop();
                stOut.push(temp);
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    void peek()
    {
        int res = this->pop();
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    bool empty()
    {
        stIn.empty() && stOut.empty();
    }
};
int main() {}