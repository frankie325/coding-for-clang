#include <iostream>
#include <vector>
using namespace std;

/*
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:

5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
示例 3:

输入: amount = 10, coins = [10]
输出: 1
*/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // 转换为完全背包问题
        // 总金额就是背包容量
        int bagSize = amount;
        // 物品数量，coins的值就是物品的重量和价值
        int n = coins.size();

        // 1.确定dp数组的含义：dp[i][j];
        //  i表示物品，j表示背包容量
        //  dp[i][j] 表示从0 -> i的物品中任意取，放进容量j的背包中，物品价值总和为amount的组合数
        vector<vector<int>> dp(n, vector<int>(bagSize + 1, 0));

        // 2.递推公式：
        // 不放物品i：背包容量为j，里面不放物品i的组合数是dp[i - 1][j]
        // 放物品i：放完物品i后，背包容量为j - coins[i]，找到放物品i之前的组合数为dp[i][j - coins[i]]
        // 总组合数为
        // dp[i][j] = dp[i-1][j] + dp[i][j - coins[i]];

        // 3.dp数组初始化：
        // 初始化最上行：如果 j 可以整除 物品0，那么装满背包就有1种组合方法。
        for (int j = 0; j <= bagSize; j++)
        {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }
        // 最左列初始化：dp[i][0] 的含义：用物品i（即coins[i]） 装满容量为0的背包 有几种组合方法。
        // 都有一种方法，即不装。所以 dp[i][0] 都初始化为
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        // 4.遍历
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= bagSize; j++)
            {
                // 如果物品重量比背包容量大，那么就不能放物品i
                if (coins[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }

        // 返回总的方法数
        return dp[n - 1][bagSize];
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    Solution s;
    int result = s.change(amount, coins);
    cout << "结果为：" << result << endl;
}