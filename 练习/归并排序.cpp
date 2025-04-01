#include <iostream>
#include <vector>
using namespace std;

// 归并排序核心：合并两个已经排好序的数组
vector<int> merge(vector<int> &left, vector<int> &right)
{
    vector<int> result;
    // 设置两个指针，从开始位置相互比较大小，小的往result中添加
    int i = 0;
    int j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
        }
    }
    // 遍历结束后，某个数组可能会有剩余，全部追加到结果数组中就可以了：
    while (i < left.size())
    {
        result.push_back(left[i++]);
    }

    while (j < right.size())
    {
        result.push_back(right[j++]);
    }
    return result;
};

// 归并排序
// [ 1, 2, 3, 4, 5 ]
vector<int> merge_sort(vector<int> &a, int start, int end)
{
    if (start == end)
        return {a[start]};
    int middle = (start + end) / 2;
    vector<int> left = merge_sort(a, start, middle);
    vector<int> right = merge_sort(a, middle + 1, end);
    return merge(left, right);
}

int main()
{
    vector<int> nums = {2, 45, 20, 11, 3, 55, 32, 89};
    vector<int> result = merge_sort(nums, 0, nums.size() - 1);
    for (int v : result)
    {
        cout << v << endl;
    }
}