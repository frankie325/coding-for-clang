#include <stdio.h>
#define MSG "I'm special"

int main()
{
    // 字符串常量属于静态存储类别：该字符串只会被存储一次，而且在程序的整个生命周期内都存在，所以字符串常量的地址是固定的
    char ar[] = MSG; // 初始化数组把静态存储区的字符串拷贝到数组中
    const char *pt = MSG; // 而初始化指针则是把字符串的地址赋给指针
    printf("address of \"I'm special\": %p \n", "I'm special"); // 0x104da3f48
    printf("address ar: %p\n", ar);                             // 0x16b05f098
    printf("address pt: %p\n", pt);                             // 0x104da3f48
    printf("address of MSG: %p\n", MSG);                        // 0x104da3f48
    printf("address of \"I'm special\": %p \n", "I'm special"); // 0x104da3f48

    // 如果打算修改字符串，而不想改变字符串常量，应该使用字符数组而不是指针
    // char *p1 = "Klingon";
    // p1[0] = "F";    
    // printf("Klingon"); // Flingon
    return 0;
}