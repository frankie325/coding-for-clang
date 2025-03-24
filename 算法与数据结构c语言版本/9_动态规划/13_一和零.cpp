#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例 1：

输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3

输出：4

解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2：

输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
*/

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // 1.确定dp数组的含义：
        // dp[i][j]：i表示最多有m个，j表示最多有n个的最大子集的大小
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 2.递推公式：
        // 把字符串看成物品，0的个数是zeroNum，1的个数是oneNum
        // 不放物品：dp[i][j]
        // 放物品：dp[i-zeroNum][j-oneNum] + 1
        // dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-oneNum] + 1);

        // 3.初始化dp数组
        dp[0][0] = 0;

        // 4.遍历顺序
        // 外层遍历物品
        for (string str : strs)
        {
            // 统计字符中0和1的个数
            int zeroNum = 0, oneNum = 0;
            for (char c : str)
            {
                if (c == '0')
                    zeroNum++;
                else
                    oneNum++;
            }

            // 遍历背包容量且从后向前遍历！
            for (int i = m; i >= zeroNum; i--)
            {
                for (int j = n; j >= oneNum; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    vector<string> v = {"10", "0001", "111001", "1", "0"};
    Solution s;
    int result = s.findMaxForm(v, 5, 3);
    cout << "方法数为：" << result << endl;
}