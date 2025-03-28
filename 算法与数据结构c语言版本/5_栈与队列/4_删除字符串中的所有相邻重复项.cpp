#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例：

输入："abbaca"
输出："ca"
解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。
之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
*/
class Solution
{
public:
    string removeDuplicates(string str)
    {
        stack<char> st;
        for (char s : str)
        {
            // 存放遍历过的元素，当遍历当前的这个元素的时候，
            // 去栈里看一下我们是不是遍历过相同数值的相邻元素
            if (!st.empty() && st.top() == s)
            {
                st.pop();
            }
            else
            {
                st.push(s);
            }
        }

        // 将栈中元素放到result字符串汇总
        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    string str = "abbaca";
    Solution s;
    string result = s.removeDuplicates(str);
    cout << "结果是：" << result << endl;
}