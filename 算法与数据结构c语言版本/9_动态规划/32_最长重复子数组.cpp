#include <iostream>
#include <vector>
using namespace std;

/*
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例：

输入：

A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3, 2, 1] 。
*/

// 版本一
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        // 1.确定dp数组的含义：
        // dp[i][j]表示，以下标i为结尾的nums1组数组 和 以下标j为结尾的nums2数组 的最长公共子数组的长度
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        // 2.递推公式：
        // 比如：求A子串[1,2,3,2] 和 B子串[3,2]的最长公共子串
        // 如果A[3] == B[1]，那么我们要看[1,2,3]和[3]的最长公共子串长度是多少，然后+1
        // if(nums1[i] == nums2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;

        // 3.初始化：
        // 要对第一行，第一列经行初始化，A[0]有一个元素和B[j]相同，则设置为1。列同理
        for (int i = 0; i < nums1.size(); i++)
            if (nums1[i] == nums2[0])
                dp[i][0] = 1;
        for (int j = 0; j < nums2.size(); j++)
            if (nums1[0] == nums2[j])
                dp[0][j] = 1;

        // 4.遍历顺序：
        for (int i = 1; i < nums1.size(); i++)
        {
            for (int j = 1; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
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
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 1, 4, 7};
    Solution s;
    int result = s.findLength(a, b);
    cout << "输出：" << result << endl;
    return 0;
}