#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
*/

class Solution
{
public:
    int numDistinct(char *s, char *t)
    {
        int len1 = strlen(s);
        int len2 = strlen(t);
        // 1.确定dp数组的含义：dp[i][j]表示s的前i个字符中，t的前j个字符出现的次数
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // 2.递推公式：
        //   bag
        //     |   |
        //     i   j
        // 比如 s[4] == t[2]的情况：
        // dp[i-1][j-1]表示ba在baeg出现的次数，因为g和g相等，所以baegg和bag的次数就是baeg和ba的次数
        // dp[i-1][j]表示bag在baeg(这里不考虑s串的最后一个g)出现的次数
        // baegg bag
        //   |     |
        //   i     j
        // s[i] != s[j]的情况：相当于把e删除去考虑
        // dp[i][j] = dp[i-1][j];

        // 3.初始化：
        if (s[0] == t[0])
        {
            dp[0][0] = 1;
        }
        else
        {
            dp[0][0] = 0;
        }
        // 0-i个s串中，t[0]子串出现的次数
        for (int i = 1; i < len1; i++)
        {
            if (s[i] == t[0])
            {
                dp[i][0] = dp[i - 1][0] + 1;
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // 0-j个t串中，s[0]子串出现的次数，因为t串的长度大于s串，所以s串中的t串出现的次数为0
        for (int j = 1; j < len2; j++)
        {
            dp[0][j] = 0;
        }

        // 4.遍历顺序：
        for (int i = 1; i < len1; i++)
        {
            for (int j = 1; j < len2; j++)
            {
                // if (j > i)
                //     continue;
                if (s[i] == t[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};

int main()
{
    char str[] = "rabbbit";
    char t[] = "rabbit";
    Solution s;
    int result = s.numDistinct(str, t);
    cout << "输出：" << result << endl;
    return 0;
}