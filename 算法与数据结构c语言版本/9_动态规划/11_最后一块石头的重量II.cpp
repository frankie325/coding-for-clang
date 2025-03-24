#include <iostream>
#include <vector>
using namespace std;

/*
题目难度：中等

有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；

如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。

最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。

示例：

输入：[2,7,4,1,8,1]
输出：1
解释：

组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。

*/

class Solution
{
    /*
    本题其实是尽量让石头分成重量相同的两堆（尽可能相同），相撞之后剩下的石头就是最小的。

    本题解题思路：
    1.两个石头相撞，结果要么为x-y，要么为y-x
    2.无论你怎么两两相碰，永远有的数字前为正号，有的为负号,因此你总可以把最终式化为一堆和减去另外一堆数字和
    3.因此我们要找的是这个集合的两个子集之和的最小差
    4.要想子集之和差最小，则两者应该尽量接近或者相等
    5.这个时候我们就可以把sum/2作为背包容量，使用01背包来解题了
    */
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (auto &&i : stones)
        {
            sum += i;
        }
        int n = stones.size();   // 物品数量
        int bagweight = sum / 2; // 背包容量

        vector<int> dp(bagweight + 1, 0);
        // 1.确定dp数组的含义：dp[j] 容量为j的背包，所背的物品价值可以最大为dp[j]
        // 一维dp数组，其实就是将上一层 dp[i-1] 这一层 拷贝的 dp[i]来。

        // 2.递推公式： dp[j]是上一个物品的最大价值
        // dp[j] = max(dp[j] , dp[j - stones[i]] + stones[i])

        // 3.初始化
        // 容量为j的背包，所背的物品价值可以最大为dp[j]，
        // 那么dp[0]就应该是0，因为背包容量为0所背的物品的最大价值就是0。

        // 4.循环
        // 外层遍历物品
        for (int i = 0; i < n; i++)
        {
            // 内层循遍历背包重量
            // !注意：内层循环一定要倒序遍历，因为dp[j]依赖于上一层物品的dp[j]值
            // !如果正序遍历，将会把依赖的上一层物品的dp[j]值重置掉
            // 遍历到j >=物品自身重量即可，背包容量小于物品重量则不能放物品了，dp[j]价值不用改变
            for (int j = bagweight; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        // 相撞之后剩下的最小石头重量
        // 在计算target的时候，target = sum / 2 因为是向下取整，
        // 所以sum - dp[target] 一定是大于等于dp[target]的。
        int result = (sum - dp[bagweight]) - dp[bagweight];
        return result;
    }
};

int main()
{
    vector<int> st = {2, 7, 4, 1, 8, 1};
    Solution s;
    int result = s.lastStoneWeightII(st);
    cout << "结果为：" << result << endl;
}