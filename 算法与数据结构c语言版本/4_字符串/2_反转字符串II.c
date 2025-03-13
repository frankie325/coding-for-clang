#include <stdio.h>
#include <string.h>

/*
给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。

如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"

abcdefg
    |
    i
*/
void reverseString(char *s, int size, int k)
{
    int left = 0;
    int right = size - 1;
    // 循环每次加2k
    for (int i = 0; i < size; i += 2 * k)
    {
        // 1. 每隔 2k 个字符的前 k 个字符进行反转
        // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
        if (i + k <= size)
        {
            left = i;
            right = i + k - 1;
        }
        else
        {
            // 剩余字符少于 k 个，则将剩余字符全部反转
            left = i;
            right = size - 1;
        }
        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
}
int main()
{
    char str[] = "abcdefg";
    printf("size of str：%lu\n", strlen(str));
    reverseString(str, strlen(str), 2);
    printf("reverse of str：%s", str);
}