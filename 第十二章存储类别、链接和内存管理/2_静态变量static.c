#include <stdio.h>

void test()
{
    // 静态局部变量，为静态存储期类别
    // 不论test执行多少次，变量a都只会在第一次执行时初始化，即只赋初值一次
    static int a; //静态局部变量a默认初始化为0，作用域在该块内
    a++;
    printf("%d ", a); 
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        test();
    }

    // 输出2 3 4 5 6
}