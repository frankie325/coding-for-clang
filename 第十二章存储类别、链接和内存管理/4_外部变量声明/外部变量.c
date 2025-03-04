#include <stdio.h>
// gcc 静态存取期.c test.c -o myprogram

extern int giants;
int Errupt; // 函数外部定义的变量，外部变量具有静态存储期

extern int g_val; // 也可以扩展一下g_val的使用范围（引用型声明）
int main()
{
    extern int Errupt; // 指出该函数使用了外部的变量Errupt
    // int Errupt; //如果不写则会创建一个局部变量Errupt
    printf("giants = %d\n", giants);
    printf("g_val = %d", g_val);
}

int g_val = 20; //(定义型声明，会建立存储空间)