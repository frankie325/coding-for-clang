#include <stdio.h>
#define STLEN 14
int main()
{
    char words[STLEN];
    // gets()读取整行输入，直到遇到换行符，然后丢弃换行符，并在字符串末尾添加空字符，C11标准中已经删除了gets()函数
    // puts()函数会在输出字符串后自动添加换行符,该函数在遇到空字符时停止输出
    puts("Enter a string, please.");
    /*
        第一个参数是一个指向字符数组的指针
        第二个参数是要读取的字符数，如果超过这个数目，fgets()会截断输入
        第三个参数是文件指针，这里是stdin，表示从标准输入读取
        按下Enter确认时，fgets不会丢弃换行符，fputs不会输出末尾的换行符，所以fgets和fputs配合使用

        fgets的返回值是指向char的指针，如果读取到文件结尾或者出现错误，返回空指针NULL
    */
    fgets(words, STLEN, stdin); // 读取用户输入的字符串
    printf("Your string twice:\n");
    fputs(words, stdout);  // 输出用户输入的字符串，不包括换行符
    printf("%s\n", words); // 输出用户输入的字符串，包括换行符

    char name1[11], name2[11];
    int count;
    puts("Enter two names.");
    // scanf()读取字符串时，以空白字符（空格、制表符、换行符）作为结束，所以scanf()读取字符串时，遇到空白字符就会停止读取
    // 如果指定了字段宽度，scanf()会在读取指定数目的字符后停止读取
    count = scanf("%5s %10s", name1, name2); // 读取两个字符串，第一个字符串最多读取5个字符，第二个字符串最多读取10个字符
    printf("I read the %d names %s and %s.\n", count, name1, name2);
}