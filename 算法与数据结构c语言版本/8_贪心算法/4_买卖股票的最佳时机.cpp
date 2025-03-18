#include <iostream>
#include <vector>
using namespace std;

/*
示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4。
随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            // 统计收益为正数的利润
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
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