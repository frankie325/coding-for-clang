#include <iostream>
#include <vector>
using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

输入描述：输入共一行，包含两个正整数，分别表示n, m

输出描述：输出一个整数，表示爬到楼顶的方法数。

输入示例：3 2

输出示例：3

提示：

当 m = 2，n = 3 时，n = 3 这表示一共有三个台阶，m = 2 代表你每次可以爬一个台阶或者两个台阶。

此时你有三种方法可以爬到楼顶。

1 阶 + 1 阶 + 1 阶段
1 阶 + 2 阶
2 阶 + 1 阶
*/

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
    }
}

int
main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution s;
    cout << "结果为：" << s.combinationSum4(nums, target) << endl;
    return 0;
}