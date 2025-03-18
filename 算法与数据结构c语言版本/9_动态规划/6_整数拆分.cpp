#include <iostream>
#include <vector>
using namespace std;

/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/

class Solution
{

public:
    int integerBreak(int n)
    {
        // 1.dp的含义：存储每个数拆分获得的最大乘积
        vector<int> dp(n + 1);

        // 2.初始化：dp[0]，dp[1]没有意义
        dp[2] = 1;
        /*
            3.递推公式：

            以4为例，即外层循环i=4时
            4可以拆分为：即内层循环
            j * (i - j)
             1*3   3继续拆分依赖于dp[3]
             2*2   2继续拆分依赖于dp[2]
            然后找到其中的最大值，也就是：

            dp[i] = max(j * (i - j), j * d[i - j], dp[i])
        */

        // 4.确定遍历顺序：从 3->n开始遍历，设置每一个数的dp[i]
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int result = s.integerBreak(10);
    cout << "输出：" << result << endl;
    return 0;
}