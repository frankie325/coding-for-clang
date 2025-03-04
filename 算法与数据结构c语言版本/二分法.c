#include <stdio.h>

int search(int arr[], int len, int target)
{

    int start = 0;
    int index = -1;
    int middle;
    /*
        二分查找
        确定边界条件关键：边界条件是否合法
        [start, end]闭区间：start <= end
        [start, end)左闭右开区间：start < end
    */

    // [start, end]闭区间：start <= end才合法
    // int end = len - 1;
    // while (start <= end)
    // {
    //     middle = (start + end) / 2;
    //     if (target > arr[middle])
    //     {
    //         start = middle + 1; //目标元素已经比middle位置的元素大，所以start = middle + 1
    //     }
    //     else if (target < arr[middle])
    //     {
    //         end = middle - 1;
    //     }
    //     else
    //     {
    //         return middle;
    //     }
    // }

    // [start, end)左闭右开区间：start < end才合法
    int end = len;
    while (start < end)
    {
        middle = (start + end) / 2;
        if (target > arr[middle])
        {
            start = middle + 1;
        }
        else if (target < arr[middle])
        {
            end = middle; // 因为是右开区间，所以end = middle
        }
        else
        {
            return middle;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    int index = search(arr, len, 5);
    printf("Index: %d\n", index);
    return 0;
}