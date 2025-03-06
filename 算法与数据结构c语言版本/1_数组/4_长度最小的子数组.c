#include <stdio.h>
/*
给定一个含有 n 个正整数的数组和一个正整数 s ，
找出该数组中满足其和 ≥ s 的长度最小的 *连续* 子数组，并返回其长度。
如果不存在符合条件的子数组，返回 0。

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/

// 暴力解法：两次循环
// 暴力解法中，是外层for循环为滑动窗口的起始位置，内层for循环为滑动窗口的终止位置，
// 用两个for循环 完成了一个不断搜索区间的过程
// int minSubArrayLen(int arr[], int len, int s)
// {
//     int result = __INT_MAX__;
//     for (int i = 0; i < len; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < len; j++)
//         {
//             sum += arr[j];
//             if (sum >= s)
//             {
//                 result = j - i + 1 < result ? j - i + 1 : result;
//                 break;
//             }
//         }
//     }
//     return result == __INT_MAX__ ? 0 : result;
// }

/*
    滑动窗口法：像条虫子一样在数组上爬行，通过两个指针来定位子数组
    1.初始化左右指针left和right为0，sum为0
    2.右指针不断向右移动，直到sum >= s，记录此时的子数组长度
    3.左指针向右移动，直到sum < s，更新子数组长度
    4.重复2和3，直到右指针到达数组末尾
*/
int minSubArrayLen(int arr[], int len, int s)
{
    int result = __INT_MAX__;
    int sum = 0;
    int left = 0;
    for (int right = 0; right < len; right++)
    {
        sum += arr[right];
        while (sum >= s)
        {
            int subLength = right - left + 1;
            result = subLength < result ? subLength : result;
            sum -= arr[left];
            left++;
        }
    }
    return result == __INT_MAX__ ? 0 : result;
}

int main()
{
    int arr[] = {2, 3, 1, 2, 4, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int s = 7;
    int result = minSubArrayLen(arr, len, s);
    printf("%d\n", result);
    return 0;
}