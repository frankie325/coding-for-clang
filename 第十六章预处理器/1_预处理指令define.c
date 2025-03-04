#include <stdio.h>
#define SQUARE(X) X *X
// #运算符是字符串化运算符，它可以将宏的参数转换为字符串常量
#define PSQR(x) printf("The square of " #x " is %d.\n", ((x) * (x)))
// ##运算符是连接运算符，它可以将两个参数连接在一起
#define XNAME(n) x##n
#define PRINTF_XN(n) printf("x" #n " = %d\n", x##n)

// ...表示可变参数，__VA_ARGS__表示可变参数的占位符
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
int main()
{
    printf("%d\n", SQUARE(5)); // 25

    // 预处理不做计算、不求值，只是简单的替换
    // 替换成5+1*5+1
    printf("%d\n", SQUARE(5 + 1)); // 11

    // 替换成100/2*2
    printf("%d\n", 100 / SQUARE(2)); // 100

    int y = 5;
    // 用“y”替换掉#x
    PSQR(y);     // The square of y is 25.
    PSQR(2 + 4); // The square of 2 + 4 is 20.

    int XNAME(1) = 14; // 等价于int x1 = 14;
    int XNAME(2) = 20; // 等价于int x2 = 20;
    PRINTF_XN(1);      // 等价于printf("x1 = %d\n", x1);
    PRINTF_XN(2);      // 等价于printf("x2 = %d\n", x2);

    int x = 30;
    PR(1, "x = %d\n", x); // 等价于printf("Message 1: x = %d\n", x);
    return 0;
}