#include <iostream>
#include <vector>
using namespace std;

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。从下标为 0 跳到下标为 1 的位置，跳  1  步，然后跳  3  步到达数组的最后一个位置。
说明: 假设你总是可以到达数组的最后一个位置。
*/

class Solution
{
public:
    int minJumpStep(vector<int> &nums)
    {
        // 只有一个元素，
        if (nums.size() == 0)
            return 0;
        int curDistance = 0;  // 当前覆盖最远距离下标
        int nextDistance = 0; // 记录走的最大步数
        int step = 0;         // 下一步覆盖最远距离下标
        for (int i = 0; i < nums.size(); i++)
        {
            nextDistance = max(i + nums[i], nextDistance); // 更新下一步覆盖最远距离下标
            if (i == curDistance)                          // 遇到当前覆盖最远距离下标
            {
                step++;                     // 需要走下一步
                curDistance = nextDistance; // 更新当前覆盖最远距离下标（相当于加油了）
                if (nextDistance >= nums.size() - 1)
                {
                    // 当前覆盖最远距到达集合终点，不用做step++操作了，直接结束
                    break;
                }
            }
        }
        return step;
    }
};

int main()
{
    vector<int> v = {2, 3, 1, 1, 4};
    Solution s;
    int result = s.minJumpStep(v);
    cout << "输出：" << result << endl;
    return 0;
}