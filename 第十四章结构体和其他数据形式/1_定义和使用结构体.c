#include <stdio.h>

// * 结构声明
struct Student
{
    char name[20];
    int age;
};

struct Book
{
    char title[20];
    char author[10];
} library, novel; // 简化变量声明，相当于全局变量

// *匿名结构体，只能使用简化变量声明
struct
{
    char name[20];
    int age;
} s1, s2;

// *嵌套的结构体
struct Expire
{
    int year;
    int month;
    int day;
};

struct Product
{
    int id;
    char name[20];
    struct Expire expire;
    struct
    {
        char first[20];
        char last[20];
    }; // 匿名结构，通过p.first，p.last可以直接访问
};

int main()
{
    // *声明为结构变量
    // struct Student stu;

    // *初始化结构变量
    struct Date
    {
        int year;
        int month;
        int day;
    } d1 = {2025, 2, 17}; // 依次赋值

    struct Product prod =
        {
            1,
            "xiaomi",
            {2025, 2, 17}, // 初始化嵌套的结构体
        };

    // C99和C11提供的指定初始化器：
    struct Student stu =
        {
            .name = "kfg",
            .age = 25,
        };

    // *访问结构成员
    printf("my name is = %s,age = %d\n", stu.name, stu.age);
    printf("product expire = %d-%d-%d\n", prod.expire.year, prod.expire.month, prod.expire.day);

    // *访问结构体和结构体成员地址

    // 引用结构体的地址
    printf("%p \n", &stu); // 0x16f9a7010
    // 引用结构体成员的地址，第一个成员的地址和结构体的地址相等
    printf("%p \n", &(stu.name)); // 0x16f9a7010
}