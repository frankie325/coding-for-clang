#include <stdio.h>

// 内部函数，只能在自己所在的add.c文件内使用
// static int Add(int a, int b)
// {
//     return a + b;
// }

// 外部函数
int Add(int a, int b)
{
    return a + b;
}