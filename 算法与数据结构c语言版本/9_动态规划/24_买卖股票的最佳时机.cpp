#include <iostream>
#include <vector>
using namespace std;

/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

示例 1：

输入：[7,1,5,3,6,4]

输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

示例 2：

输入：prices = [7,6,4,3,1]

输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // 1.确定dp数组的含义：可以看成是本金0元，买入股票，利润就是负数
        // *持有是指延续之前买入的状态，不持有是指延续之前卖出的状态 
        // dp[i][0]表示第i天持有股票的最大利润 
        // dp[i][1]表示第i天不持有股票的最大利润

        // 2.递推公式：注意题目规定了只能买卖一次股票
        // dp[i-1][0]表示前一天持有股票的最大利润，也就是之前就买了股票
        // -prices[i]表示之前一直没买股票，第i天买入股票，因为只能买一次，所以这里是第一次买，即0 - prices[i]
        // dp[i][0] = max(dp[i-1][0], -prices[i]);

        // dp[i-1][1]表示前一天不持有股票的最大利润，也就是之前就卖了股票或一直没买股票
        // dp[i-1][0] + prices[i]表示之前买了股票，第i天卖出股票
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);

        // 3.初始化：
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        // 4.遍历顺序：
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};

int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    Solution s;
    int result = s.maxProfit(v);
    cout << "输出：" << result << endl;
    return 0;
}