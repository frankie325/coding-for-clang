#include <stdio.h>
#define MSG "I'm special"

int main()
{
    // 字符串常量属于静态存储类别：该字符串只会被存储一次，而且在程序的整个生命周期内都存在，所以字符串常量的地址是固定的
    char ar[] = MSG;                                            // 初始化数组把静态存储区的字符串拷贝到数组中
    const char *pt = MSG;                                       // 而初始化指针则是把字符串的地址赋给指针
    printf("address of \"I'm special\": %p \n", "I'm special"); // 0x104da3f48
    printf("address ar: %p\n", ar);                             // 0x16b05f098
    printf("address pt: %p\n", pt);                             // 0x104da3f48
    printf("address of MSG: %p\n", MSG);                        // 0x104da3f48
    printf("address of \"I'm special\": %p \n", "I'm special"); // 0x104da3f48

    // char *p1 = "Klingon"; 字符串字面量是只读的，不能被修改，如果需要修改字符串，应该使用字符数组
    char p1[] = "Klingon"; // 字符串字面量的拷贝赋值给p1
    // p1[0] = "F"; //error "F" 是一个字符串字面量，它是一个包含两个字符的数组：'F' 和 '\0'
    p1[0] = 'F';       // 使用单引号 'F' 表示单个字符
    printf("Klingon"); // Klingon
    return 0;
}