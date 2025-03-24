#include <iostream>
#include <vector>
using namespace std;

/*
有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
*/

int main()
{
    // n表示物品数量
    int n = 3, bagweight = 4; // bagweight代表行李箱空间

    // cout << "请输入物品数量n：";
    // cin >> n;
    // cout << "请输入背包容量bagweight：";
    // cin >> bagweight;

    vector<int> weight = {1, 3, 4};   // 存储每件物品所占空间
    vector<int> value = {15, 20, 30}; // 存储每件物品价值

    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> weight[i];
    // }
    // for (int j = 0; j < n; ++j)
    // {
    //     cin >> value[j];
    // }
    vector<int> dp(bagweight + 1, 0);
    // 1.确定dp数组的含义：dp[j] 容量为j的背包，所背的物品价值可以最大为dp[j]
    // 一维dp数组，其实就是将上一层 dp[i-1] 这一层 拷贝的 dp[i]来。

    // 2.递推公式： dp[j]是上一个物品的最大价值
    // dp[j] = max(dp[j], dp[j-weight[i]]+ value[i])

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
        for (int j = bagweight; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << "最大价值为：" << dp[bagweight] << endl;
}