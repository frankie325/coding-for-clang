#include <iostream>
#include <vector>
using namespace std;

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例  1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例  2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
#
*/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // 只有一个元素，就是能达到
        if (nums.size() == 0)
            return true;
        int cover = 0;
        for (int i = 0; i <= cover; i++) // 注意这里是小于等于cover
        {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) // 说明可以覆盖到终点了
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> v = {2, 3, 1, 1, 4};
    Solution s;
    bool result = s.canJump(v);
    cout << "输出：" << result << endl;
    return 0;
}