#include <stdio.h>
struct Student
{
    char name[30];
    float score;
} s1[3]; // 结构体数组

struct Person
{
    char name[20];
    int count;
};

int main()
{
    // 声明结构体数组并初始化结构体数组
    struct Person p3[3] = {
        {"张三", 0},
        {"李四", 0},
        {"刘五", 0},
    };

    for (int i = 0; i < 3; i++)
    {
        printf("The score of %s is %d\n", p3[i].name, p3[i].count);
    }
    return 0;
}