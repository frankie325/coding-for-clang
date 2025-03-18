#include <iostream>
#include <vector>
using namespace std;

/*
*组合：组合是不强调元素顺序的

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

[1,2,3,4]
示例: 输入: n = 4, k = 2 输出: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4], ]
*/

/*
 !回溯法三部曲:
    1.确定递归函数的返回值以及参数
    2.回溯函数终止条件
    3.单层搜索的过程
*/

class Solution
{
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果
    void back_tracing(int n, int k, int startIndex)
    {
        // 回溯函数终止条件：如果长度为2，则返回
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }

        // 搜索过程
        /*
            *剪枝优化：需要满足条件 列表中剩余元素（n-i）大于等于 所需要元素个数才能继续往下找
            1.已经选择的元素个数：path.size();
            2.所需需要的元素个数为: k - path.size();
            3.列表中剩余元素（n-i） >= 所需需要的元素个数（k - path.size()）
            4.在集合n中至多要从该起始位置 : i <= n - (k - path.size()) + 1，开始遍历
        */
        // for (int i = startIndex; i <= n; i++)
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);         // 处理节点
            back_tracing(n, k, i + 1); // 递归
            path.pop_back();           // 回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k, int startIndex)
    {
        back_tracing(n, k, startIndex);
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> result = s.combine(4, 2, 1);

    for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++)
    {
        vector<int> arr = *it;
        cout << "组合：";
        for (vector<int>::iterator vit = arr.begin(); vit != arr.end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}