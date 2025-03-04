#include <stdio.h>

// 枚举类型
enum Sex
{
    MALE, // 枚举常量，为int类型
    FEMALE,
    SECRET
};

int main()
{
    enum Sex s = MALE;
    // MALE = 4; //枚举常量不能修改

    // 枚举常量默认从0开始被赋值
    printf("%d\n", MALE);   // 0
    printf("%d\n", FEMALE); // 1
    printf("%d\n", SECRET); // 2

    enum Weekday
    {
        mon = 1,
        // 如果只给中间的枚举常量赋值，那么后面的常量会被赋予后续的值
        tue = 100,
        wed
    };
    printf("%d\n", mon); // 1
    printf("%d\n", tue); // 100
    printf("%d\n", wed); // 101
    return 0;
}