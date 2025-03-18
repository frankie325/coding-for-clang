#include <iostream>
#include <vector>
using namespace std;

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