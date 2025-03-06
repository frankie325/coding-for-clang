#include <stdio.h>

/*
题目描述

给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。

输入描述

第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间，直至文件结束。

输出描述

输出每个指定区间内元素的总和。

输入示例
5
1
2
3
4
5
0 1
1 3

输出示例
3
9
*/

int main()
{
    /*
    前缀和：
    前缀和的思想是重复利用计算过的子数组之和，从而降低区间查询需要累加计算的次数。
    前缀和在涉及计算区间和的问题时非常有用！
    例如：
    sum[1] = arr[0] + arr[1];
    sum[5] = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5];
    sum[5] - sum[1] = arr[2] + arr[3] + arr[4] + arr[5];
    */
    int n;
    scanf("%d", &n);
    int arr[n];
    int sum[n];

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        total += arr[i];
        sum[i] = total; // 计算前缀和
    }
    int start, end;
    scanf("%d %d", &start, &end); // 区间查询
    int result = 0;
    if (start == 0) // 当查询开始索引为0时，直接输出前缀和
    {
        result = sum[end];
    }
    else
    {
        result = sum[end] - sum[start - 1]; // 区间和
    }
    printf("%d\n", result);
    return 0;
}