#include <iostream>
#include <vector>
using namespace std;

/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值  g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

示例  1:

输入: g = [1,2,3], s = [1,1]
输出: 1 解释:你有三个孩子和两块小饼干，3 个孩子的胃口值分别是：1,2,3。虽然你有两块小饼干，由于他们的尺寸都是 1，你只能让胃口值是 1 的孩子满足。所以你应该输出 1。
示例  2:

输入: g = [1,2,7,10], s = [1,3,5,9]
输出: 3
解释:你有四个孩子和四块小饼干，4 个孩子的胃口值分别是 1,2,7,10
9满足7，5满足2，3满足1，所以你应该输出3
*/

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // 按从小到大排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) // 遍历胃口
        {
            if (index >= 0 && s[index] > g[i]) // 遍历饼干
            {
                result++;
                index--;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> g;
    g.push_back(1);
    g.push_back(2);
    g.push_back(7);
    g.push_back(10);

    vector<int> s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(5);
    s.push_back(9);

    Solution sol;
    int result = sol.findContentChildren(g, s);
    cout << "输出：" << result << endl;
    return 0;
}