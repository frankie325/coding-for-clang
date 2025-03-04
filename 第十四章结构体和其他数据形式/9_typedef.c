#include <stdio.h>

// 类型定义，自定义类型，相当于起个别名
typedef unsigned int uint;

// 定义一个结构体Stu类型，并命名为student
typedef struct Stu
{
    char name[20];
    int age;
} student;

int main()
{
    uint b = 20;

    // 这两句话是等价的，都是定义一个结构体
    struct Stu s;
    student s2;

    // 定义数组类型
    // int parr[10]; //parr是数组名
    typedef int parr[10]; // parr为新的数组类型的类型名
    parr arr2;            // arr2是一个数组，数组有10个元素，每个元素时int
    return 0;
}