#include <iostream>
#include <vector>
using namespace std;

/*
{0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040}
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。
该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
也就是： F(0) = 0，F(1) = 1 F(n) = F(n - 1) + F(n - 2)，其中 n > 1 给你n ，请计算 F(n) 。


!动态规划五部曲：
1.确定dp数组（dp table）以及下标的含义
2.确定递推公式
3.dp数组如何初始化
4.确定遍历顺序
5.举例推导dp数组
*/

class Solution
{
public:
    int fib(int N)
    {
        if (N <= 1)
            return N;
        // 1.确定dp数组（dp table）以及下标的含义
        // 2.确定递推公式 dp[n] = de[n-1] + dp[n-2]
        vector<int> dp(N + 1, 0);
        // 3.dp数组如何初始化
        dp[0] = 0;
        dp[1] = 1;
        // 4.确定遍历顺序：从左往右
        for (int i = 2; i <= N; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};

int main()
{
    Solution s;
    int result = s.fib(5);
    cout << "输出：" << result << endl;
    return 0;
}