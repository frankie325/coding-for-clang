#include <stdio.h>
#include <stdlib.h>
/*

给你一个按非递减顺序排序的整数数组nums，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]


双指针法：
数组平方的最大值就在数组的两端，不是最左边就是最右边
从两端开始比较，大的放在result的最后面
两个指针依次向中间移动
*/
int *sortSquare(int arr[], int len)
{
    int i = 0, j = len - 1;
    // int result[len]; //不能返回一个局部变量的地址，因为局部变量在函数执行完后会被销毁
    // 申请一个新数组
    int k = len - 1;
    int *result = (int *)malloc(len * sizeof(int));
    if (result == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    for (i = 0; i <= j;)
    {
        // 依次比较两个端的大小，大的放在result最后面
        if (arr[i] * arr[i] > arr[j] * arr[j])
        {
            result[k] = arr[i] * arr[i];
            k--; // 从后往前放
            i++;
        }
        else
        {
            result[k] = arr[j] * arr[j];
            k--;
            j--;
        }
    }
    return result;
}

int main()
{
    int a[] = {-4, -1, 0, 3, 10};
    int len = sizeof(a) / sizeof(a[0]);
    int *result = sortSquare(a, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}