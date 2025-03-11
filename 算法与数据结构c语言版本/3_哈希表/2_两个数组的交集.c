#include <stdio.h>
#include <stdlib.h>
/*
给定两个数组，编写一个函数来计算它们的交集
nums1 = [1,2,2,1]
nums2 = [2,2]

输出 [2]

本题后面 力扣改了 题目描述 和 后台测试数据，增添了 数值范围：小于1000个
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

小于1000个可以使用数组来做哈希表
*/

int *intersection(int nums1[], int nums1Size, int nums2[], int nums2Size, int *returnSize)
{
    int hash[1000] = {0};
    int *result = (int *)calloc(nums1Size < nums2Size ? nums1Size : nums2Size, sizeof(int));
    int resultIndex = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        hash[nums1[i]] = 1; // 记录nums1中所有元素
    }

    for (int i = 0; i < nums2Size; i++)
    {
        // 如果与哈希表中记录的值有一样的，则说明为公共元素
        if (hash[nums2[i]] == 1)
        {
            result[resultIndex] = nums2[i];
            resultIndex++;
            hash[nums2[i]] = 0; // 重置hash中的值，防止重复添加
        }
    }
    *returnSize = resultIndex;
    return result;
}

int main()
{
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    int len2 = sizeof(nums2) / sizeof(nums2[0]);
    // int intersect[] = {0}; //不能将函数返回的指针赋值给一个固定大小的数组
    int *intersect;
    int size = 0;
    intersect = intersection(nums1, len1, nums2, len2, &size);
    for (int i = 0; i < size; i++)
    {
        printf("交集元素为：%d", intersect[i]);
    }
}