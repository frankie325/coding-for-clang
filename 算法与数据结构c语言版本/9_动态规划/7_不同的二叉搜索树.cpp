#include <iostream>
#include <vector>
using namespace std;

/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

n=3时，有5种二叉搜索树
*/

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        // 1.确定dp的含义：1-n为节点的二叉树搜索树的个数为dp[i]
        /*
        2.递推公式：
        i为二叉树节点的个数n
        j为二叉树的根节点数字：从1->n
        dp[i] = 左子树的二叉搜索树的个数 * 右子树的二叉搜索树的个数
        左子树：左边节点数字大小比根节点小，所以左边节点个数为j-1
        右子树：右边节点数字大小比根节点大，所以右边节点个数为i-j
        dp[i] = dp[j - 1] * dp[i - j]
        */

        // 3.初始化
        dp[0] = 1; // 0个节点时，二叉搜索树个数设为1
        dp[1] = 1; // 1个节点时，二叉搜索树个数设为1，可由递推公式算出

        // 4.循环：从小到大循环，因为下一个二叉树搜索树的个数依赖于前一个二叉树搜索树的个数
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int result = s.numTrees(3);
    cout << "输出：" << result << endl;
    return 0;
}