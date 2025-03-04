#include <stdio.h>

/*
    删除数组中的元素：
    数组的元素在内存地址中是连续的，不能单独删除数组中的某个元素，只能覆盖
*/
int delete_element(int arr[], int len, int target)
{
    /*
        双指针法：通过一个快指针和慢指针在一个for循环下完成两个for循环的工作，不需要使用额外的数组空间
        快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
        慢指针：指向更新 新数组下标的位置

        时间复杂度：O(n)
        空间复杂度：O(1)
    */
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < len; fastIndex++)
    {
        // 当快指针指向的元素等于目标元素时，则慢指针不会更新，快指针继续向前移动
        if (arr[fastIndex] != target)
        {
            arr[slowIndex] = arr[fastIndex]; // 快指针指向的元素更新到新数组
            slowIndex++;
        }
    }
    return slowIndex; // 慢指针位置就是新数组的长度
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3, 6, 7, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int newLen = delete_element(arr, len, target);
    for (int i = 0; i < newLen; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}