#include <stdio.h>
#include <stdlib.h>

int main()
{
    // void*
    int aa = 1;
    float ss = 1.1;
    void *pc; // 无类型指针（不指向确定数据的类型）
    pc = &aa;
    pc = &ss;
    // *pc = 2.2; // 编译不通过，无类型指针不能进行解引用操作
    // pc + 1;  // 编译不通过，指针操作也不行

    // 申请10个整型空间 - 栈区 10 * 4byte = 40byte
    int arr[10] = {0};
    // *动态申请内存 - 堆区
    // int *p = (int* )malloc(40); // 向堆区申请40个字节的空间
    // malloc返回值类型为void*，这里使用(int* )进行强制类型转换

    // calloc第一个参数为存储单元的数量，第二个参数为每个存储单元的大小
    // calloc还有一个特性就是会把快中的所有位都设置为0
    int *p = (int *)calloc(10, sizeof(int));

    // 开辟失败返回空指针
    if (p == NULL)
    {
        printf("动态内存分配失败\n");
        return -1;
    }

    // 使用动态申请的空间
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d", *(p + i));
    }

    // 发现空间不够使用了，想调整空间大小，若重新开辟失败则返回空指针
    int *ptr = (int *)realloc(p, 15 * sizeof(int)); // 重新为p指针分配内存
    if (ptr != NULL)
    {
        // 重新开辟成功，再赋值给p指针
        p = ptr;
    }

    // 释放空间，否则导致内存泄露
    free(p);
    p = NULL; // p指向空指针

    //
    return 0;
}