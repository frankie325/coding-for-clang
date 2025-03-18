#include <iostream>
#include <vector>
using namespace std;

/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为： [ [7], [2,2,3] ]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为： [ [2,2,2,2], [2,3,3], [3,5] ]
*/

class Solution
{
private:
    int sum = 0;
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果
    void back_tracing(vector<int> &candidate, int target, int startIndex)
    {
        if (sum > target)
        {
            return;
        }

        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        // *剪枝优化：
        // 其实如果已经知道下一层的sum会大于target，就没有必要进入下一层递归了。
        // for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        for (int i = startIndex; i < candidate.size(); i++)
        {
            path.push_back(candidate[i]);
            sum += candidate[i];
            back_tracing(candidate, target, i); // 不用i+1了，表示可以重复读取当前的数
            sum -= candidate[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(vector<int> &candidate, int target)
    {
        back_tracing(candidate, target, 0);
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> candidate;
    candidate.push_back(2);
    candidate.push_back(3);
    candidate.push_back(5);
    vector<vector<int>> result = s.combine(candidate, 8);

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