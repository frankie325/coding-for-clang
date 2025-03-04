#include <stdio.h>

// 使用命令编译两个文件
// gcc index.c add.c -o index


// 函数的外部声明 
extern int Add(int, int);

int main()
{
    int sum;
    sum = Add(1, 2);
    printf("sum = %d", sum);
    return 0;
}
