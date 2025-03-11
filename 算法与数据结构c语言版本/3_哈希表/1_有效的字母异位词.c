#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1: 输入: s = "anagram", t = "nagaram" 输出: true

示例 2: 输入: s = "rat", t = "car" 输出: false

也就是判断两个字符串是不是由相同的字母组成，且字母个数都相同，即字母异位词
*/

int isAnagram(char *s, char *t)
{
    int len1 = strlen(s), len2 = strlen(t);
    if (len1 != len2)
        return false;

    // 定义一个数组叫做record用来上记录字符串s里字符出现的次数，数组其实就是一个简单哈希表
    int record[26] = {0};
    for (int i = 0; i < len1; i++)
    {
        // 因为字符a到字符z的ASCII是26个连续的数值，所以字符a映射为下标0，相应的字符z映射为下标25
        record[s[i] - 'a']++; //+1记录该字母出现的次数
    }

    for (int i = 0; i < len2; i++)
    {
        record[s[i] - 'a']--; // 第二个字符串中，相同的字母出现一次就 -1
    }

    for (int i = 0; i < 26; i++)
    {
        // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
        if (record[i] != 0)
            return false;
    }

    // record数组所有元素都为零0，说明字符串s和t是字母异位词
    return true;
}

int main()
{
    char *str1 = "anagram";
    char *str2 = "nagaram";
    int b = isAnagram(str1, str2);
    printf("Is two strings above anagram：%d", b);
}