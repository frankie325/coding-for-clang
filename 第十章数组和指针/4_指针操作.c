#include <stdio.h>

int main()
{
    int urn[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;
    int **ptr4;

    ptr1 = urn; // 把一个地址赋给指针，数组名是数组第一个元素的地址
    ptr2 = &urn[2]; // 把数组第三个元素的地址赋给指针
    ptr4 = &ptr1; // 指针变量也有自己的地址和值，把ptr1的地址赋给指针
    printf("*ptr4 = %p\n", ptr4); // 输出ptr1的地址
    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1); // *ptr1解引用，输出ptr1指向的值

    // 指针加法
    ptr3 = ptr1 + 4; // 指针加法，ptr3指向数组的第五个元素
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4)); // *(ptr1 + 4)解引用，输出ptr1 + 4指向的值
    ptr1++; // 指针自增，指向数组的第二个元素
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    // 指针减法
    ptr2--; // 指针自减，指向数组的第二个元素
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
    --ptr1; // 恢复为初始值
    ++ptr2; // 恢复为初始值
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

    // 一个指针减去另一个指针，得到的是两个指针之间的元素个数
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);
}