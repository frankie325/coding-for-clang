#include <stdio.h>
#include <string.h>
/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

示例 1：
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
*/
void reverseString(char *s, int size)
{
    /*
        双指针法：
        ["h","e","l","l","o"]
          |               |
          i               j    交换i、j元素
          i++, j--
    */
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char str[] = "hello";
    // int size = sizeof(str) / sizeof(str[0]) - 1;
    printf("size of str：%lu\n", strlen(str));
    reverseString(str, strlen(str));
    printf("reverse of str：%s", str);
}