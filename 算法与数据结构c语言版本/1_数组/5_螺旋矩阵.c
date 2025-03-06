#include <stdio.h>
#include <stdlib.h>
/*
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:
输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]

3 * 3的矩阵
[ 1, 2, 3 ]
[ 8, 9, 4 ]
[ 7, 6, 5 ]

坚持循环不变量原则：左闭右开区间
*/
int **generateMatrix(int n)
{
    // 分配n * n的二维数组动态内存
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));
    }

    int loop = n / 2; // 循环次数
    int startX = 0, startY = 0;
    int i, j; // i为行索引，j为列索引
    int offset = 1;
    int count = 1;
    int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
    while (loop--)
    {
        i = startX;
        j = startY;
        // 下面开始的四个for就是模拟转了一圈
        // 模拟填充上行从左到右(左闭右开)
        for (; j < n - offset; j++)
        {
            result[i][j] = count++;
        }
        // 模拟填充右列从上到下(左闭右开)
        for (; i < n - offset; i++)
        {
            result[i][j] = count++;
        }
        // 模拟填充下行从右到左(左闭右开)
        for (; j > startY; j--)
        {
            result[i][j] = count++;
        }
        // 模拟填充左列从下到上(左闭右开)
        for (; i > startX; i--)
        {
            result[i][j] = count++;
        }
        startX++;    // 起始行索引加1
        startY++;    // 起始列索引加1
        offset += 1; // 偏移量加1
    }

    // 如果n为奇数，需要单独填充中间的位置
    if (n % 2 == 1)
    {
        result[mid][mid] = count;
    }
    return result;
}
int main()
{
    int n = 3;
    int **result = generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < n; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}
