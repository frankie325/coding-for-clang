#include <iostream>
#include <vector>
using namespace std;

/*
给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）

以这种方式修改数组后，返回数组可能的最大和。

示例 1：

输入：A = [4,2,3], K = 1
输出：5
解释：选择索引 (1) ，然后 A 变为 [4,-2,3]。
示例 2：

输入：A = [3,-1,0,2], K = 3
输出：6
解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
示例 3：

输入：A = [2,-3,-1,5,-4], K = 2
输出：13
解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
提示：

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
*/

class Solution
{
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

public:
    /*
        第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
        第二步：从前向后遍历，遇到负数将其变为正数，同时K--
        第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
        第四步：求和
    */
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // 第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++)
        {
            // 第二步：从前向后遍历，遇到负数将其变为正数，同时K--
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        // 第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
        if (k % 2 == 1)
            nums[nums.size() - 1] *= -1;

        // 第四步：求和
        int result = 0;

        for (auto &&num : nums)
        {
            result += num;
        }
        return result;
    }
};

int main()
{
    vector<int> v = {2, -3, -1, 5, -4};
    Solution s;
    int result = s.largestSumAfterKNegations(v, 2);
    cout << "输出：" << result << endl;
    return 0;
}