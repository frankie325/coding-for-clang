#include <stdio.h>

/*
    形参arr是一个指向int类型的指针，指向数组的首地址
    只有在形参是，C才会把int arr[]解释为int *arr，所以int arr[]和int *arr是等价的

    由于函数原型可以省略，所以下面四种原型是等价的
    int sum(int arr[], int n);
    int sum(int [], int);
    int sum(int *arr, int n);
    int sum(int *, int);
*/
int sum(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total;
}

int main()
{
    int i;
    int arr[] = {1, 2, 3, 4, 5};
    // 传址调用，传递数组的首地址作为实参，
    i = sum(arr, 5);
    printf("总和为：%d\n", i);
}