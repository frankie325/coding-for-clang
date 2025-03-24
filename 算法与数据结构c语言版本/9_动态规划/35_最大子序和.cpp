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
        // 1.确定dp数组的含义：dp[i]表示以下标i结尾的数组的最大子序和
        vector<int> dp(nums.size(), 0);

        // 2.递推公式：
        // dp[i -1] + nums[i]表示前一个数组的最大子序和加上当前元素
        // nums[i]表示，前面都不要了，从i位置重新计算
        // dp[i] = max(nums, dp[i - 1] + nums[i]);

        // 3.初始化：
        dp[0] = nums[0];
        int result = dp[0];

        // 4.遍历顺序：
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            if (dp[i] > result)
                result = dp[i]; // result 保存dp[i]的最大值
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