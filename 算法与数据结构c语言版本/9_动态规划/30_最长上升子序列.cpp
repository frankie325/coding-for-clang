#include <iostream>
#include <vector>
using namespace std;

/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1
*/
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        // 1.确定dp数组的含义：以nums[i]结尾的最长递增子序列的长度为dp[i]。
        vector<int> dp(nums.size(), 1);

        // 2.递推公式：
        // if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        // j表示从0到i-1的所有元素
        // 用nums[i] 和 nums[j]比较，因为nums[j]是dp[j]这个最长递增子序列的最后一个元素
        // 如果nums[i] > nums[j]，nums[i]可以加入这个最长递增子序列，则为dp[i]等于dp[j] + 1;
        // dp[i]可以理解为循环时上一个j计算出来的最长递增子序列长度，所以需要加max进行比较

        // 以nums【i】为结尾的最长递增子序列的长度可以由
        // nums【0】为结尾的最长递增子序列长度、nums[1]为结尾的最长长度、……nums【i-1】为结尾的最长长度 比较得到

        // 3.初始化
        // dp[0] = 1，只有一个元素，长度为1

        // 4.遍历顺序
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if (dp[i] > result)
                    result = dp[i]; // 取长的子序列
            }
        }

        return result;
    }
};

int main()
{
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    int result = s.lengthOfLIS(v);
    cout << "输出：" << result << endl;
    return 0;
}