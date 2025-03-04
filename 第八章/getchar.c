#include <stdio.h>

int main()
{
    // getchar读取每个字符，包括空格、制表符和换行符
    // 输入一连串字符，会进入缓冲区，但是getchar只会读取第一个字符
    // 例如  输入：abcdefg
    //      输出：a
    char ch = getchar();
    putchar(ch);
    return 0;
}
