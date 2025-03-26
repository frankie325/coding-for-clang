#include <iostream>
#include <vector>
using namespace std;

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明： 所有数字（包括目标数）都是正整数。解集不能包含重复的组合。

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/
class Solution
{
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果
    int sum;

public:
    void backtracking(vector<int> &candidates, int target, int startIndex, vector<bool> &used)
    {
        // *剪枝优化：如果元素总和大于n，则继续往下没意义了
        if (sum > target)
        {
            return;
        }

        // 回溯函数终止条件：
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        // 单层搜索过程
        for (int i = startIndex; i < candidates.size(); i++)
        {
            // 要对同一树层使用过的元素进行跳过
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false)
            {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, target, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), false); // 用来记录同一树枝上的元素是否使用过
        sum = 0;
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return result;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    Solution s;
    vector<vector<int>> result = s.combinationSum2(candidates, 8);
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