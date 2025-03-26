#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例: 输入: "aab" 输出: [ ["aa","b"], ["a","a","b"] ]

回文串是指正读和反读都一样的字符串。
*/

class Solution
{
    vector<vector<string>> result;
    vector<string> path; // 放已经回文的子串
public:
    void backtracking(const string &s, int startIndex)
    {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i))
            {
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    // 判断是不是回文串
    bool isPalindrome(const string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};

int main()
{
    string str = "aab";
    Solution s;
    vector<vector<string>> result = s.partition(str);
    for (vector<vector<string>>::iterator it = result.begin(); it != result.end(); it++)
    {
        vector<string> arr = *it;
        cout << "组合：";
        for (vector<string>::iterator vit = arr.begin(); vit != arr.end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}