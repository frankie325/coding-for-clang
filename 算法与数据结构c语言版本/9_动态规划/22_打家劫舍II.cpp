#include <iostream>
#include <vector>
using namespace std;

/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

示例 1：

输入：nums = [2,3,2]

输出：3

解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

示例 2：

输入：nums = [1,2,3,1]

输出：4

解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。偷窃到的最高金额 = 1 + 3 = 4 。

示例 3：

输入：nums = [0]

输出：0
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
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
            if (i == nums.size() - 1)
            {
            }
            else
            {
            }
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};

int main()
{
    vector<int> nums = {2, 3, 2};
    // 选取左边到倒数第二个房屋，求最大值
    // 选取第二个到最右边的房屋，求最大值
    // 比较两者的最大值
    vector<int> left;
    left.assign(nums.begin(), nums.end() - 1);
    vector<int> right;
    right.assign(nums.begin() + 1, nums.end());
    Solution s;
    int result = max(s.rob(left), s.rob(right));
    cout << "结果为：" << result << endl;
}