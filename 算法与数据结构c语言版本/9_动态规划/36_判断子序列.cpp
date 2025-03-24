#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false
提示：

0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。
*/

// 版本一
class Solution
{
public:
    bool isSubsequence(char *text1, char *text2)
    {
        int len1 = strlen(text1);
        int len2 = strlen(text2);

        // 1.确定dp数组的含义：
        // dp[i][j]表示，以下标i为结尾的text1子串 和 以下标j为结尾的text2子串 的最长公共子序列的长度
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        int result = 0;
        // 2.递推公式：
        // 如果test1[i] == test2[j]，那么dp[i][j] = dp[i - 1][j - 1] + 1;
        // *与最长公共子序列的区别：如果test1[i] != test2[j]，那么dp[i][j] = dp[i][j-1];
        // if(text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        // else dp[i][j] = dp[i][j-1];

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
                    dp[i][j] = dp[i][j - 1];
                }
                if (dp[i][j] > result)
                    result = dp[i][j];
            }
        }

        // 最后判断dp[len1][len2]是否等于s字符串的长度
        return result == len1;
    }
};

int main()
{
    char a[] = "abc";
    char b[] = "ahbgdc";
    Solution s;
    bool result = s.isSubsequence(a, b);
    cout << "输出：" << result << endl;
    return 0;
}