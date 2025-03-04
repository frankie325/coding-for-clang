#include <stdio.h>

// 冒泡排序
void bubble_sort(int a[], int len)
{
    // 外层循环控制比较的轮数，全部排玩需要length - 1
    for (int i = 1; i < len; i++)
    {
        // 内层循环控制比较的次数，比较的次数依次减少，第一轮为length - 1 ， 第二为轮length - 2
        for (int j = 0; j < len - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// 选择排序
void select_sort(int a[], int len)
{
    // 外层循环控制比较的轮数，全部排玩需要length - 1轮
    for (int i = 0; i < len - 1; i++)
    {
        // 找到最小值的下标，然后交换
        int minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

// 插入排序，从后往前比较，如果前面的数大于后面的数，则交换
void insert_sort(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int j = i + 1;
        while (a[j] < a[j - 1] && j > 0)
        {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}

// 希尔排序，分组插入排序
void shell_sort(int a[], int len)
{
    int gap = len / 2;
    while (gap >= 1)
    {
        for (int i = gap; i < len; i++)
        {
            int j = i;
            while (a[j] < a[j - gap] && j > gap)
            {
                int temp = a[j];
                a[j] = a[j - gap];
                a[j - gap] = temp;
                j -= gap;
            }
        }
        gap /= 2;
    }
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int j = start;
    for (int i = start; i <= end; i++)
    {
        if (a[i] <= pivot)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    return j - 1;
}

// 快速排序
void quick_sort(int a[], int start, int end)
{
    if (end - start < 1)
        return;
    int pivot = partition(a, start, end);
    quick_sort(a, start, pivot - 1);
    quick_sort(a, pivot + 1, end);
}

int main()
{

    int arr[] = {2, 45, 20, 11, 3, 55, 32, 89};
    int len = sizeof(arr) / sizeof(arr[0]);
    // bubble_sort(arr, len);
    // select_sort(arr, len);
    // insert_sort(arr, len);
    // shell_sort(arr, len);
    quick_sort(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}