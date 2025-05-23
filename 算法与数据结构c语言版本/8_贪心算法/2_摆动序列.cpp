#include <iostream>
#include <vector>
using namespace std;

/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3)  是正负交替出现的。相反, [1,4,7,2,5]  和  [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:

输入: [1,7,4,9,2,5]
输出: 6
解释: 整个序列均为摆动序列。
示例 2:

输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
示例 3:

输入: [1,2,3,4,5,6,7,8,9]
输出: 2
*/
class Solution
{

public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        int preDiff = 0; // 前一对差值
        int curDiff = 0; // 当前差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值

        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff; // 注意这里，只在摆动变化的时候更新prediff
            }
        }

        return result;
    }
};
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(17);
    v.push_back(5);
    v.push_back(10);
    v.push_back(13);
    v.push_back(15);
    v.push_back(10);
    v.push_back(5);
    v.push_back(16);
    v.push_back(8);

    Solution s;
    int result = s.wiggleMaxLength(v);
    cout << "输出：" << result << endl;
    return 0;
}