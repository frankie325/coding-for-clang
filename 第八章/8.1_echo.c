#include <stdio.h>

int main()
{
    char ch;

    // 输入字符先逐个送入缓冲区，按下回车键，程序读取缓冲区的内容
    while ((ch = getchar()) != '#')
    {
        putchar(ch);
    }

    return 0;
}