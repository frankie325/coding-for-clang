#include <iostream>
#include <vector>
using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1 阶 + 1 阶
2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1 阶 + 1 阶 + 1 阶
1 阶 + 2 阶
2 阶 + 1 阶

第一层：1
第二层：2
第三层：3 （第二层+第三层）
第四层：5 （第三层+第四层）
爬楼梯的本质就是斐波那契数列，难点就是找出它们的递推关系
*/
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int result = s.climbStairs(4);
    cout << "输出：" << result << endl;
    return 0;
}