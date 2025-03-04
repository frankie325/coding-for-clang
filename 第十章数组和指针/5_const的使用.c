#include <stdio.h>

// 形参使用const修饰，表示不能修改形参指向的数组内容，保护数组中的数据
int test(const int ar[])
{
    // ar[0] = 10; // 不能修改ar指向的数组内容
    return 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    test(arr);

    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    const double *pt = rates; // pt指向rates的第一个元素
    // *pt = 100.0; // !不能修改pt指向的数组内容
    // pt[2] = 100.0; // !不能修改pt指向的数组内容
    rates[2] = 100.0; // 可以修改rates数组内容，因为rates不是const

    // *把const数据和非const数据的地址初始化为指向const的指针或为其赋值是合法的
    const double locked[4] = {100.0, 200.0, 300.0, 400.0};
    const double *pt2 = rates; // pt2指向rates的第一个元素
    pt2 = locked; // pt2指向locked的第一个元素
    pt2 = &locked[1]; // pt2指向locked的第二个元素

    // *只能把非const数据的地址赋给普通指针
    double *pt3 = rates; // pt3指向rates的第一个元素
    // pt3 = locked; // !不能把const数据的地址赋给普通指针
    // pt3 = &locked[1]; // !不能把const数据的地址赋给普通指针

    // *创建指针时可以使用const两次，该指针表示既不能更改它所指向的地址，也不能更改它所指向的地址上的值
    const double *const p3 = rates; // p3是一个指向const double的const指针，不能修改p3的值和p3指向的值
    // p3 = locked; // !不能修改p3的值
    // *p3 = 100.0; // !不能修改p3指向的值
}