#include <stdio.h>

int main()
{
    int i = 010, j = 10;          // 010是八进制数，等于十进制的8
    printf("%d\n", i);            // 8
    printf("%d\n", j);            // 10
    printf("%d, %d\n", ++i, j--); // 9, 10

    /*
    在C语言中，以下值被视为假值（false）：
    整数值0：任何整数类型的0值都被视为假值。
    浮点数值0.0：任何浮点类型的0.0值都被视为假值。
    空指针（NULL）：任何指针类型的空指针值都被视为假值。
    */ 
    if(0){

    }else{
        printf("0 is false\n");
    }
    
    return 0;
}