#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 $O(n \log n)$ , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
*/

class Solution
{
public:
    class mycomparison
    {
    public:
        // 按照
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        // 对频率排序：定义一个小顶堆，大小为k
        // 第一个参数是存储的数据类型
        // 第二个是底层的实现方式
        // 第三个是仿函数，控制排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            // 存储频率
            pri_que.push(*it);
            // 如果大于k，则从堆顶把小的频率给剔除掉
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
            // 剩下的k个就是频率最高的
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution s;
    vector<int> result = s.topKFrequent(nums, 2);
    for (auto &&i : result)
    {
        cout << i << endl;
    }
    return 0;
}