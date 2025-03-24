#include <iostream>
#include <vector>
using namespace std;

/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
示例：

输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
一共有5种方法让最终目标和为3。
*/

class Solution
{
public:
    /*
    这道题目咋眼一看和动态规划背包啥的也没啥关系。
    本题要如何使表达式结果为target，
    既然为target，那么就一定有 left组合 - right组合 = target。
    left + right = sum，而sum是固定的。right = sum - left
    left - (sum - left) = target 推导出 left = (target + sum)/2 。
    target是固定的，sum是固定的，left就可以求出来。
    此时问题就是在集合nums中找出和为left的组合。
     */
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        // 如果target + sum 是奇数，那么就没有方案
        // 例如sum是5，target是2 的话其实就是无解
        if ((target + sum) % 2 == 1)
            return 0;
        // 同时如果target 的绝对值已经大于sum，那么也是没有方案的。
        if (abs(target) > sum)
            return 0;                     // 此时没有方案
        int bagSize = (target + sum) / 2; // 背包容量

        // 1.dp数组的含义：
        // dp[i][j]表示从0->i个物品中任意取，放进j容量背包的组合方法数

        // 2.递推公式：
        // 不放物品i，背包容量为j，里面不放物品i的组合方法数是dp[i - 1][j]
        // 放物品i，背包容量为j - nums[i]，容量背包的组合方法数就是dp[i - 1 ][j-nums[i]]
        // dp[i][j] = dp[i - 1][j] + dp[i - 1 ][j-nums[i]]
        vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));

        // 3.dp数组初始化：
        // 初始化最上行
        // 只有背包容量为 物品0 的容量的时候 组合方法数才为1，其余都为0
        if (nums[0] <= bagSize)
            dp[0][nums[0]] = 1;

        // 初始化最左列，最左列其他数值在递推公式中就完成了赋值
        dp[0][0] = 1;

        // 如果 物品数值就是0，按照组合数量求，即 2^t 。
        int numZero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                numZero++;
            // 第一列初始化
            dp[i][0] = (int)pow(2.0, numZero);
        }

        // 4.循环：
        for (int i = 1; i < nums.size(); i++) // 行，遍历物品
        {
            for (int j = 0; j <= bagSize; j++) // 列，遍历背包
            {
                if (j < nums[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                }
            }
        }
        // 返回总的方法数
        return dp[nums.size() - 1][bagSize];
    }

    // 一维方法
    int findTargetSumWays2(vector<int> &nums, int target)
    {
        int sum = 0;
        for (auto &&i : nums)
        {
            sum += i;
        }
        if ((target + sum) % 2 == 1)
        {
            return 0;
        }
        if (abs(target) > sum)
            return 0;                     // 此时没有方案
        int bagSize = (target + sum) / 2; // 背包容量

        // 1.dp数组的含义：dp[j]表示，背包容量为j时，物品的组合方法数
        vector<int> dp(bagSize + 1, 0);

        // 2.递推公式：
        // 背包容量为j时，
        // 里面不放物品i的组合方法数是dp[j]
        // 放物品的组合数为dp[j - nums[i]]
        // dp[j] = dp[j] + dp[j - nums[i]];

        // 3.dp数组初始化：
        dp[0] = 1;

        // 4.遍历顺序：
        // 外层遍历物品
        // 内层遍历背包重量，从后往前遍历
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bagSize; j >= nums[i]; j--)
            {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }

        return dp[bagSize];
    }
};

int main()
{
    vector<int> v = {1, 1, 1, 1, 1};
    Solution s;
    // int result = s.findTargetSumWays(v, 3);
    int result = s.findTargetSumWays2(v, 3);
    cout << "方法数为：" << result << endl;
}