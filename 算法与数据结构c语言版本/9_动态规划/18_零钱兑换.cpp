#include <iostream>
#include <vector>
using namespace std;

/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
示例 4：

输入：coins = [1], amount = 1
输出：1
示例 5：

输入：coins = [1], amount = 2
输出：2
*/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int bagSize = amount;
        int n = coins.size();

        // 1.确定dp的含义：dp[j]表示凑成总金额j的最少硬币个数
        vector<int> dp(bagSize + 1, INT_MAX);
        // dp[]

        // 2.递推公式：
        // dp[j] = min(dp[j], dp[j - coins[i]] + 1)

        // 3.初始化
        dp[0] = 0;

        // 4.遍历顺序：
        for (int i = 0; i < coins.size(); i++)
        {
            // 内层循环遍历背包重量：正序遍历，因为每个硬币可以使用无限次
            for (int j = coins[i]; j <= bagSize; j++)
            {
                if (dp[j - coins[i]] != INT_MAX)
                { // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return dp[bagSize] == INT_MAX ? -1 : dp[bagSize];
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution s;
    int result = s.coinChange(coins, amount);
    cout << "结果为：" << result << endl;
}