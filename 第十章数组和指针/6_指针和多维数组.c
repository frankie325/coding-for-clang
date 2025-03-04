#include <stdio.h>

int main()
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}}; // 内含 int 数组的数组

    // zippo是该数组首元素的地址，zippo的值和&zippo[0]的值相同
    printf("zippo = %p\n", zippo);         // 0x16d5670b0
    printf("&zippo[0] = %p\n", &zippo[0]); // 0x16d5670b0
    // 而zippo[0]本身是一个内含两个整数的数组，所以zippo[0]的值和&zippo[0][0]的值相同
    printf("zippo[0] = %p\n", zippo[0]);         // 0x16d5670b0
    printf("&zippo[0][0] = %p\n", &zippo[0][0]); // 0x16d5670b0

    // 给指针或地址 + 1，其值会增加对应类型大小的数值，zippo与zippo[0]不同，
    // zippo指向的对象( {2, 4} )占用了两个int大小，zippo[0]指向的对象()只占用一个int大小
    printf("zippo + 1 = %p\n", zippo + 1);       // 0x16d5670b8
    printf("zippo[0] + 1 = %p\n", zippo[0] + 1); // 0x16d5670b4

    // zippo表示数组的首元素zippo[0]，但是zippo[0]本身就是一个int类型的地址，
    // 所以解引用 *zippo的值就是&zippo[0][0]的值
    printf("*zippo = %p\n", *zippo);             // 0x16d5670b0
    printf("&zippo[0][0] = %p\n", &zippo[0][0]); // 0x16d5670b0

    // zippo[0]是数组首元素zippo[0][0]的地址，所以 *zippo[0]为zippo[0][0]的值
    printf("*(zippo[0]) = %d\n", *(zippo[0])); // 2

    // **zippo与*&zippo[0][0]等价，这相当于zippo[0][0]，简而言之，zippo就是地址的地址
    // !地址的地址或指针的指针就是双重间接
    printf("**zippo = %d\n", **zippo); // 2

    // !指向多维数组的指针
    int(*pz)[2]; // pz指向一个内含两个int类型值的数组
    int *pax[2]; // 因为[]优先级高于*，pax是一个内含两个指针的数组
    pz = zippo;  // 指针名pz和数组名的用法一样，pz指向的地址就是 &zippo[0]，
    // pz指向数组的首元素的地址
    printf("pz = %p", pz);         // 0x16d5670b0
    printf("pz + 1 = %p", pz + 1); // 0x16d5670b8
    printf("*pz = %p", *pz);       // 0x16d5670b0
    printf("**pz = %p", **pz);     // 2
}