#include <iostream>
#include <vector>
using namespace std;

/*
难度：中等

给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4
所有可能的组合为： (1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (1, 3) (2, 1, 1) (2, 2) (3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。

顺序不同的序列被视作不同的组合
也就是排列数，而不是组合数
*/

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // 使用一维dp数组，dp[i]表示目标和为i的排列数
        vector<unsigned int> dp(target + 1, 0);

        // 初始化
        dp[0] = 1;

        // 求排列数，外层遍历背包
        // 对于排列问题，则应当先遍历背包，后遍历物品，这样，对于每个背包容量
        // 我们能依次记录以各个物品结尾的可行方案，即考虑了物品的顺序。
        for (int i = 0; i <= target; i++)
        {
            // 内层遍历物品
            for (int j = 0; j < nums.size(); j++)
            {
                // 当容量为i时，从物品0->j中任意取，排列的数量
                if (i >= nums[j])
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution s;
    cout << "结果为：" << s.combinationSum4(nums, target) << endl;
    return 0;
}