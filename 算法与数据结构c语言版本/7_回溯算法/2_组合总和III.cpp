#include <iostream>
#include <vector>
using namespace std;

/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：
    所有数字都是正整数。
    解集不能包含重复的组合。

示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]
示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution
{

private:
    int sum = 0;
    vector<int> path;
    vector<vector<int>> result;

    // n：目标和，也就是题目中的n。
    // k：题目中要求k个数的集合。
    // sum：已经收集的元素的总和，也就是path里元素的总和。
    // startIndex：下一层for循环搜索的起始位置。
    void back_tracing(int n, int k, int startIndex)
    {
        // *剪枝优化：如果元素总和大于n，则继续往下没意义了
        if (sum > n)
            return;
        if (path.size() == k)
        {
            if (sum == n)
                result.push_back(path);
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }

        // *剪枝优化：
        // for (int i = startIndex; i <= 9; i++)
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            sum += i;
            back_tracing(n, k, startIndex + 1);
            sum -= i;
            path.pop_back();
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
    vector<vector<int>> result = s.combine(9, 3, 1);

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