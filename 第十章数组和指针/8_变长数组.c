#include <stdio.h>
int sum2d(int rows, int cols, int ar[rows][cols]);

int main()
{
    // int n;
    // scanf("%d", &n);
    // 变长数组不能在声明时进行初始化
    // 因为变长数组的长度是在运行时确定的，而初始化列表是在编译时确定的
    // int arr[n] = 0; //error

    int rows = 4;
    int cols = 4;
    // 变长数组不是指可以修改已创建数组的大小，一旦创建了变长数组，它的大小则保持不变。
    // 这里的变是指：可以使用变量指定数组的维度
    int arr[rows][cols];

    int junk[3][4] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6},
    };

    int junk2[2][6] = {
        {2, 4, 6, 8, 2, 3},
        {3, 5, 7, 9, 4, 5},
    };
    printf("3x4 total = %d\n", sum2d(3, 4, junk));
    printf("2x6 total = %d", sum2d(2, 6, junk2));
}

// 形参中声明的变长数组并未实际创建数组
int sum2d(int rows, int cols, int ar[rows][cols])
{
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            tot += ar[r][c];
        }
    }
    return tot;
}