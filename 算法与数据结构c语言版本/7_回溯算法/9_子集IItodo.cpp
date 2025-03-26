#include <iostream>
#include <vector>
using namespace std;

/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]
*/

class Solution
{
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果
    void backtracking(vector<int> &nums, int startIndex)
    {
        // *与组合的区别就是每次遍历，都要把结构记录下来
        // 收集子集，要放在终止添加的上面，否则会漏掉自己
        result.push_back(path);
        // 回溯函数终止条件：可以不写，因为startIndex已经等于nums.size()，最后不会走下面的for循环量
        // if (path.size() == nums.size())
        // {
        //     return;
        // }

        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);   // 处理节点
            backtracking(nums, i + 1); // 递归
            path.pop_back();           // 回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> result = s.subsets(nums);

    for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++)
    {
        vector<int> arr = *it;
        cout << "子集：";
        for (vector<int>::iterator vit = arr.begin(); vit != arr.end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}