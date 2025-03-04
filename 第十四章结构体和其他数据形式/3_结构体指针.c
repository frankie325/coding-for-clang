#include <stdio.h>

struct Student
{
    char name[20];
    int age;
};
struct Person
{
    char name[20];
    int count;
};
int main()
{
    struct Student stu = {"张三", 20};
    printf("%p\n", &stu);      // 结构体的地址
    struct Student *ps = &stu; // *结构体的指针

    // 用指针访问成员，两种方式
    // printf("%s %d\n", (*ps).name, (*ps).age);
    printf("%s %d\n", ps->name, ps->age); // -> 指向运算符

    struct Person p[3] = {
        {"张三", 1},
        {"李四", 2},
        {"王五", 3},
    };

    // *结构体数组指针
    struct Person *pt = p;
    for (int i = 0; i < 3; i++)
    {
        /*
                            Memory Address    | Data
                            ------------------|-------------------------
            第一次 pt ->     0x1000            | {"张三", 1}
            第二次 pt ->     0x1020            | {"李四", 2}
            第三次 pt ->     0x1040            | {"王五", 3}
        */
        printf("The score of %s is %d\n", pt->name, pt->count);
        pt++;
    }

    return 0;
}