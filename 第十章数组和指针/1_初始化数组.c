#include <stdio.h>

// 冒泡排序
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    //! 数组初始化
    /*
        一维数组在内存中的存放形式：
        内存地址    │ 数据值  │ 数组索引
        ──────────┼────────┼──────
        0x1000    │   1    │  [0]
        0x1004    │   2    │  [1]
        0x1008    │   4    │  [2]
        0x100C    │   8    │  [3]
        0x1010    │   16   │  [4]
        0x1014    │   32   │  [5]
        0x1018    │   64   │  [6]
        0x101C    │   128  │  [7]

        关键说明：
        一维数组在内存中是连续存放的
        每个整型元素占用 4 字节（32位系统中）
        数组名 powers 实际上是指向数组第一个元素的指针
        相邻元素的地址相差 4 个字节（因为是 int 类型）
        可以通过 powers + i 或 &powers[i] 来获取第 i 个元素的地址
        内存地址是从低地址向高地址增长的
    */
    int powers[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    for (int i = 0; i < sizeof(powers) / sizeof(powers[0]); i++)
    {
        printf("%d\n", powers[i]);
    }
    printf("-----------------\n");

    //! 常量数组
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // days[1] = 29; // 错误，days是常量数组，不能修改
    // [2] = 3,4,5表示从第二位开始赋值为3,4,5
    // 不足的位数用0填充
    int arr[6] = {
        [2] = 3, // 第二位赋值为3
        4,
        5};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d\n", arr[i]);
    }

    //! 数组越界
    // printf("%d\n", powers[8]);
    printf("-----------------\n");

    // 指定数组大小时，方括号中使用整型常量表达式
    int arr2[4];
    int arr3[5 * 2 + 1];
    int arr4[sizeof(int) + 1];

    int arr5[] = {20, 10, 15, 2, 4, 10};
    bubble_sort(arr5, sizeof(arr5) / sizeof(arr5[0]));
    for (int i = 0; i < sizeof(arr5) / sizeof(arr5[0]); i++)
    {
        printf("%d\n", arr5[i]);
    }   
    return 0;
}