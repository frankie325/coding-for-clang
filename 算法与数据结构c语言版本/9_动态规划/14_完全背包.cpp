#include <iostream>
#include <vector>
using namespace std;

/*
完全背包：完全背包与01背包的区别就是物品可以无限放多次
有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
每件物品有无限件，求解将哪些物品装入背包里物品价值总和最大。
*/

int main()
{
    // n表示物品数量
    int n = 3, bagweight = 4; // bagweight代表行李箱空间

    // cout << "请输入物品数量n：";
    // cin >> n;
    // cout << "请输入背包容量bagweight：";
    // cin >> bagweight;

    vector<int> weight = {1, 3, 4};   // 存储每件物品所占空间
    vector<int> value = {15, 20, 30}; // 存储每件物品价值

    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> weight[i];
    // }
    // for (int j = 0; j < n; ++j)
    // {
    //     cin >> value[j];
    // }
    vector<vector<int>> dp(n, vector<int>(bagweight + 1, 0));
    // 1.确定dp数组的含义：dp[i][j]
    //  i表示物品，j表示背包容量
    //  dp[i][j] 表示从0 -> i的物品中任意取，放进容量j的背包中，价值总和的最大值

    // 2.递推公式：
    // 不放物品i：背包容量为j，里面不放物品i的最大价值是dp[i - 1][j]
    // 放物品i：放完物品i后，背包容量为j - weight[i]
    // *区别：完全背包不是从i-1开始，而是从i开始，因为物品i可以无限放多次
    // 即dp[i][j-weight[i]]，再加上物品i的价值value[i]即为最大价值
    // dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i]] + value[i]);

    // 3.初始化
    // 背包容量为0时，即j=0的一列全部设为0，定义dp时已经初始化为0了
    // 选择物品1时，即i=0的一行且j>物品1的重量，
    // *区别：初始第一行，背包容量可以放多个物品0
    for (int j = weight[0]; j <= bagweight; j++)
    {
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    }

    // 4.循环
    for (int i = 1; i < n; i++)
    {
        // *内存循环可以正序遍历，因为物品i可以无限放多次
        for (int j = 0; j <= bagweight; j++)
        {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j]; // 如果装不下这个物品,那么就继承dp[i - 1][j]的值
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
        }
    }

    cout << "最大价值为：" << dp[n - 1][bagweight] << endl;
}