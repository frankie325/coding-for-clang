#include <iostream>
#include <vector>
using namespace std;

/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。   偷窃到的最高金额 = 1 + 3 = 4 。

示例 2：
输入：[2,7,9,3,1]
输出：12 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。   偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        // 1.确定dp数组的含义：dp[i]表示前i个房屋能偷窃到的最高金额
        vector<int> dp(nums.size(), 0);
        // 2.递推公式:
        // 不偷i房屋：dp[i] = dp [i-1]
        // 偷i房屋：dp[i] = dp[i-2] + nums[i]
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        // 3.初始化：
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // 4.遍历顺序：
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    int result = s.rob(nums);
    cout << "结果为：" << result << endl;
}