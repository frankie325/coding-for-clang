#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/

class Solution
{
    vector<string> result;
    int pointNum; // IP地址中点的个数
public:
    void backtracking(string &s, int startIndex)
    {
        // 逗点数量为3时，分隔结束
        if (pointNum == 3)
        {
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1))
            {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            // 判断[startIndex,i] 这个区间的子串是否合法
            if (isValid(s, startIndex, i))
            {
                s.insert(i + 1, "."); // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2); // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;
                s.erase(i + 1, 1); // 回溯删掉逗点
            }
            else
                break; // 如果不合法，结束本层循环
        }
    }

    // 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
    bool isValid(const string &s, int start, int end)
    {
        if (start > end)
        {
            return false;
        }

        // 如果子串长度大于1，而且以0开头，那么是不合法的
        if (start != end && s[start] == '0')
        {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            // 字符串中含有非数字字符，不合法
            if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }
            // 转换为10进制数字
            num = num * 10 + (s[i] - '0');
            // 如果大于255，不合法
            if (num > 255)
            {
                return false;
            }
        }

        return true;
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        pointNum = 0;
        result.clear();
        backtracking(s, 0);
        return result;
    }
};

int main()
{
    string str = "25525511135";
    Solution s;
    vector<string> result = s.restoreIpAddresses(str);
    for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << "ip地址：" << *it << endl;
    }
}