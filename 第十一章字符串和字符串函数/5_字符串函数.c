#include <stdio.h>
#include <string.h>
#include <ctype.h>
void fit(char *string, unsigned int size);

int main()
{
    char mesg[] = "Things should be as simple as possible,"
                  "but not simpler.";
    puts(mesg);
    fit(mesg, 38);
    puts(mesg);                                     // Things should be as simple as possible
    puts("Let's look at some more of the string."); // 从第39个字符开始输出
    puts(mesg + 39);                                // but not simpler

    printf("************strcat************\n");
    char mesg1[80] = "Things should be as simple as possible,";
    char mesg2[] = "but not simpler.";
    // strcat()函数将第二个字符串的备份追加到第一个字符串的末尾，第二个字符串不变
    strcat(mesg1, mesg2);
    puts(mesg1); // Things should be as simple as possible,but not simpler.
    printf("************strncat************\n");
    char msg3[80] = "Things should be as simple as possible,";
    char msg4[] = "but not simpler.";
    // strcat函数无法检查第一个数组是否能容纳第二个数组，所以可能会导致数组越界
    // strncat()函数可以指定追加的字符数
    strncat(msg3, msg4, 10);
    puts(msg3); // Things should be as simple as possible,but not si
    printf("************strcmp************\n");
    char str1[] = "hello";
    char str2[] = "world";
    // strcmp()函数比较两个字符串，如果两个字符串相等，返回0；如果第一个字符串小于第二个字符串，返回负数(ASCII的差值)；如果第一个字符串大于第二个字符串，返回正数
    printf("%d\n", strcmp(str1, str2)); // -15
    printf("************strncmp************\n");
    char str3[] = "astronomy";
    char str4[] = "astrophobia";
    char str5[] = "astounding";
    // strncmp()函数比较两个字符串的前n个字符，第三个参数指定比较的字符数
    // 比较前五个字符，前五个字符相等，则返回0
    printf("%d\n", strncmp(str3, str4, 5)); // 0
    printf("%d\n", strncmp(str4, str5, 5)); // 3
    printf("************strcpy************\n");
    char str6[80];
    char str7[] = "hello world";
    // strcpy()函数将第二个字符串的备份复制到第一个字符串中，第二个字符串不变
    strcpy(str6, str7);
    puts(str6); // hello world
    printf("************strncpy************\n");
    char str8[80];
    char str9[] = "hello world";
    // strncpy()函数可以指定复制的字符数
    strncpy(str8, str9, 5);
    puts(str8); // hello
    printf("************sprintf************\n");
    char str10[80];
    int year = 2021;
    // sprintf()函数将格式化的数据存储到字符串中，用法和printf()函数类似
    sprintf(str10, "The year is %d", year);
    puts(str10); // The year is 2021

    printf("************toupper************\n");
    char str11[] = "hello world";
    // toupper()函数将小写字母转换为大写字母
    for (int i = 0; i < strlen(str11); i++)
    {
        str11[i] = toupper(str11[i]);
    }
    puts(str11); // HELLO WORLD
    printf("************ispunct************\n");
    char str12[] = "hello, world!";
    // ispunct()函数检查字符是否是标点符号
    for (int i = 0; i < strlen(str12); i++)
    {
        if (ispunct(str12[i])) // 如果是标点符号
        {
            str12[i] = ' '; // 将标点符号替换为空格
        }
    }
    puts(str12); // hello  world
    printf("************strchr************\n");
    char str13[] = "hello world";
    // strchr()函数在字符串中查找字符
    char *ptr = strchr(str13, 'o');
    puts(ptr); // o world
    printf("************strrchr************\n");
    char str14[] = "hello world";
    // strrchr()函数在字符串中查找字符，从后往前查找
    char *ptr1 = strrchr(str14, 'o');
    puts(ptr1); // orld
    return 0;
}

// 用于截断字符串
void fit(char *string, unsigned int size)
{
    // strlen()返回字符串的长度，不包括空字符
    // strlen的返回值是size_t类型，size_t是无符号整型，与int类型不同 
    if (strlen(string) > size)
    {
        string[size] = '\0';
    }
}