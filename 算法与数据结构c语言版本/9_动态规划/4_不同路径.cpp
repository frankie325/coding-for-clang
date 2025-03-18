#include <iostream>
#include <vector>
using namespace std;

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

输入：m = 3, n = 7
输出：28
*/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 1.确定dp数组的含义:
        // dp[i][j] ：表示从（0 ，0）出发，到(i, j) 有dp[i][j]条不同的路径。
        // 2.确定递推公式：dp[i][j] = dp[i-1][j] + dp[i][j-1]
        // 3.初始化：首先dp[i][0]一定都是1，因为从(0, 0)的位置到(i, 0)的路径只有一条，那么dp[0][j]也同理
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        // 4.确定遍历顺序：
        // 这里要看一下递推公式dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，
        // dp[i][j]都是从其上方和左方推导而来，那么从左到右一层一层遍历就可以了。
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
    int result = s.uniquePaths(3, 7);
    cout << "输出：" << result << endl;
    return 0;
}