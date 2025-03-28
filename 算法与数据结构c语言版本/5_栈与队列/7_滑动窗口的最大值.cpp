#include <iostream>
#include <string>
#include <deque>
using namespace std;

/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
*/
class MyQueue
{
private:
    deque<int> que; // 使用deque来实现单调队列

public:
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
    void pop(int val)
    {
        if (!que.empty() && val == que.front())
        {
            que.pop_front();
        }
    }

    // 如果push的数值大于尾部元素的数值，那么就将队列尾部的数值弹出，直到push的数值小于等于队列尾端元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小的了。
    void push(int val)
    {
        while (!que.empty() && val > que.back())
        {
            que.pop_back();
        }
        que.push_back(val);
    }

    // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
    int front()
    {
        return que.front();
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) // 先将前k的元素放进队列
        {
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值

        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);          // 滑动窗口移除最前面元素
            que.push(nums[i]);             // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;
    vector<int> result = s.maxSlidingWindow(nums, 3);
    for (auto &&i : result)
    {
        cout << i << endl;
    }
}