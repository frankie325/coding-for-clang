#include <iostream>
#include <vector>
using namespace std;

/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出: [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
*/
class Solution
{
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果

public:
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        // 如果path长度和数组长度一样，则说明找到了一组排列
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        // 因为是排列，所以从0开始
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false); // 用来记录同一树枝上的元素是否使用过
        path.clear();
        result.clear();
        backtracking(nums, used);
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> result = s.permute(nums);
    for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++)
    {
        vector<int> arr = *it;
        cout << "排列：";
        for (vector<int>::iterator vit = arr.begin(); vit != arr.end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}