#include <iostream>
#include <vector>
using namespace std;

/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。

示例 1：

输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。
示例 2：

输入：cost = [1,100,1,1,1,100,1,1,100,1]
输出：6
解释：你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。
*/
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // 1.确定dp数组的含义：从该阶梯爬的费用以及之前花费费用的总和
        vector<int> dp(cost.size() + 1);
        // 2.确定递推公式：从dp[i-1]调到dp[i]的费用：到d[i-1]的总费用 + 从d[i-1]往上爬的费用
        // 要比较从[i-1]到i和[i-2]到i的总费用，取最小值
        // 3.初始化：默认第一步都是不花费体力的
        dp[0] = 0;
        dp[1] = 0;
        // 4.确定遍历顺序：从左往右
        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        // 5.举例推导dp数组：打印出来查看结果是否正确
        for (auto &&value : dp)
        {
            cout << value << " ";
        }
        cout << endl;

        return dp[cost.size()];
    }
};

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution s;
    int result = s.minCostClimbingStairs(cost);
    cout << "输出：" << result << endl;
    return 0;
}