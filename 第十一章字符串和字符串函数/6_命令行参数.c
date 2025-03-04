#include <stdio.h>

// argc是命令行参数的个数，argv是一个指向字符串的指针数组，每个字符串都是一个命令行参数
// 执行命令： ./第十一章字符串和字符串函数/6_命令行参数 Resistance is futile.
// The command line has 4 arguments:
// 0: ./第十一章字符串和字符串函数/6_命令行参数 第一个参数在大部分系统中一般是程序的名称
// 1: Resistance
// 2: is
// 3: futile.
int main(int argc, char *argv[])
{
    int count; // 命令行参数的个数
    printf("The command line has %d arguments:\n", argc);
    for (count = 0; count < argc; count++)
    {
        printf("%d: %s\n", count, argv[count]);
    }
    printf("\n");
    return 0;
}