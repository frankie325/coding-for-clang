#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/*
示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明：尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/
class Solution
{
private:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
    vector<string> result; //最终结果
    string str = ""; //目标字符

    void back_tracing(string input, int deep = 0)
    {
        // 终止条件：当深度等于输入字符串长度时，说明找到了一个组合
        if (deep == input.size())
        {
            result.push_back(str);
            return;
        }

        // 将index指向的数字转为int
        int index = input.at(deep) - '0';
        // 取数字对应的字符集
        string letters = letterMap[index];
        for (int i = 0; i < letters.size(); i++)
        {
            str.push_back(letters[i]);     // 选择
            back_tracing(input, deep + 1); // 递归
            str.pop_back();                // 回溯
        }
    }

public:
    vector<string> combine(string input)
    {
        back_tracing(input, 0);
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> result = s.combine("23");

    for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << "组合：" << *it << endl;
    }
}