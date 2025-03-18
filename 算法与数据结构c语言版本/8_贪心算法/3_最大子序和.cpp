#include <iostream>
#include <vector>
using namespace std;

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释:  连续子数组  [4,-1,2,1] 的和最大，为  6。


局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小。

全局最优：选取最大“连续和”
*/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if (count > result) // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            if (count < 0) // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
                count = 0;
        }
        return result;
    }
};

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    int result = s.maxSubArray(v);
    cout << "输出：" << result << endl;
    return 0;
}