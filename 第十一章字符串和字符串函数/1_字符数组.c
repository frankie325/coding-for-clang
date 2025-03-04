#include <stdio.h>

int main()
{
    // 字符数组
    char words[20] = "hello world"; // 字符串字面量，末尾有'\0'，表示字符串结束
    printf("%s\n", words);
    // words = 'test'; // words是一个数组地址，不能直接赋值
    // 初始化字符数组
    char words2[20] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'}; // 末尾加上'\0'，表示字符串结束
    char words3[20] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};       // 末尾没有加上'\0'，不是字符串，而是字符数组
    printf("%s\n", words2);
    printf("%s\n", words3);

    // 让编译器自动计算数组长度
    char words4[] = "hello world"; // 等价于 char words4[12] = "hello world";
}