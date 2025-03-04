#include <stdio.h>

int main()
{
    // char类型变量只能表示0 ~ 255的无符号整数，
    // 但是EOF的值是 -1，所以用int
    int ch;

    // EOF表示end of file，可用来检测文件结尾
    // 在大多数UNIX和LINUX系统中，按下ctrl + d 会传输文件结尾信号
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }

    // 重定向输入：< 符号是UNIX和DOS/Windows的重定向运算符，该运算符使words文件与stdin流相关联，把文件中的内容导入echo_eof程序
    // 在命令行输入 ‘./8.2_echo_eof < word.txt’ 将会读取word的内容

    // 重定向输出：> 符号 把输入字符的副本重定向至文件
    // 在命令行输入 ‘./8.2_echo_eof > myword.txt’ 将会把输入的字符输出到myword文件
    return 0;
}