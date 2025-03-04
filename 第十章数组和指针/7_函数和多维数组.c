#include <stdio.h>

// 声明二维数组的形参，可以使用指向数组和指向多维数组的指针
// void sum(int arr[][4], int rows) {}
void sum(int (*ar)[4], int rows) {}

// 声明N维数组时，只能省略最左边方括号的值
// int sum(int arr[][12][20][30], int rows){}
// int sum(int (*ar)[12][20][30], int rows){}
int main()
{
    int junk[3][4] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}};
    sum(junk, 0);
}