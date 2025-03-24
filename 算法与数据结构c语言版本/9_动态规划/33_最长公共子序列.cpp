#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

示例 1:

输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace"，它的长度为 3。
示例 2:

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
示例 3:

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
*/

// 版本一
class Solution
{
public:
    int longestCommonSubsequence(char *text1, char *text2)
    {
        int len1 = strlen(text1);
        int len2 = strlen(text2);

        // 1.确定dp数组的含义：
        // dp[i][j]表示，以下标i为结尾的text1子串 和 以下标j为结尾的text2子串 的最长公共子序列的长度
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        int result = 0;
        // 2.递推公式：
        // 如果test1[i] == test2[j]，那么dp[i][j] = dp[i - 1][j - 1] + 1;
        // 如果test1[i] != test2[j]，那么dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        // if(text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        // else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        // 3.初始化：
        // 要对第一行，第一列经行初始化

        // 先判断第一个字符是否相等
        if (text1[0] == text2[0])
            dp[0][0] = 1;
        else
            dp[0][0] = 0;

        // 再循环第一行和第一列
        for (int j = 1; j < len2; j++)
            if (text1[0] == text2[j])
                dp[0][j] = 1;
            else
                dp[0][j] = dp[0][j - 1];
        for (int i = 1; i < len1; i++)
            if (text1[i] == text2[0])
                dp[i][0] = 1;
            else
                dp[i][0] = dp[i - 1][0];
        // 4.遍历顺序：
        for (int i = 1; i < len1; i++)
        {
            for (int j = 1; j < len2; j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] > result)
                    result = dp[i][j];
            }
        }

        return result;
    }
};

int main()
{
    char a[] = "abcdefghijk";
    char b[] = "aefg";
    Solution s;
    int result = s.longestCommonSubsequence(a, b);
    cout << "输出：" << result << endl;
    return 0;
}