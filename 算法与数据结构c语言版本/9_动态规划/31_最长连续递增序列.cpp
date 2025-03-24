#include <iostream>
#include <vector>
using namespace std;

/*
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

示例 1：

输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
示例 2：

输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
*/
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {

        // 1.确定dp数组的含义：以nums[i]结尾的最长递增子序列的长度为dp[i]。
        vector<int> dp(nums.size(), 1);

        // 2.递推公式：
        // 当第i个元素大于第i-1个元素时，最长递增子序列的长度为dp[i-1] + 1
        // if (nums[i] > nums[i - 1]) dp[i] = dp[i-1] + 1;

        // 3.初始化
        // dp[0] = 1，只有一个元素，长度为1

        // 4.遍历顺序
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};

int main()
{
    vector<int> v = {1, 3, 5, 4, 7};
    Solution s;
    int result = s.findLengthOfLCIS(v);
    cout << "输出：" << result << endl;
    return 0;
}