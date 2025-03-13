#include <stdio.h>
#include <string.h>

/*
前缀表（next数组）

记录每个位置的最长相等前后缀长度
用于在不匹配时快速回退，避免重复比较
例如："aabaaf" 的前缀表为 [-1,0,1,0,1,2]

  i
  |
aabaaf  s[i-1] == s[cn],next[i] = cn+1,i++,cn++; [-1,0,1]
|
cn

   i
   |
aabaaf  cn>0, cn = next[cn]; cn大于0时继续往前跳 [-1,0,1]
 |
 cn

   i
   |
aabaaf  next[i] = 0; cn=0时，没有相等的前后缀 [-1,0,1,0]
|
cn
*/
void getNext(char *s, int *next)
{
    int size = strlen(s);
    // int next[size];
    // 第一位和第二位的 最长相等前后缀是固定的
    next[0] = -1;
    next[1] = 0;
    // i表示当前要求next值的位置
    // cn表示当前要和前一个字符比对的下标
    int i = 2, cn = 0;
    while (i < size)
    {
        if (s[i - 1] == s[cn])
        {
            next[i] = cn + 1;
            i++;
            cn++;
        }
        else if (cn > 0)
        {
            cn = next[cn];
        }
        else
        {
            next[i] = 0;
            i++;
        }
    }
    // return next;
}
/*
KMP算法，主要用于字符串匹配，它的核心是利用已经部分匹配的信息，避免重复比较
      x
      |
'aabaabaafa';
'aabaaf'
      |
      y


      x = 5
      |
'aabaabaafa';
   'aabaaf'
      |
      y = 2

    3     x = 9
    |     |
'aabaabaafa';
   'aabaaf'
          |
          y = 6
当y指向最后时，找到了子字符串，子字符串在s1中的索引为 x - y
*/
int kmp(char *s1, char *s2)
{
    int n = strlen(s1);
    int m = strlen(s2);
    // s1对比的位置为x,s2对比的位置为y
    int x = 0, y = 0;
    int next[m];
    getNext(s2, next);
    // 如果x = n, 则s1字符串走到了最后，没有匹配到
    // 如果y = m, 则s2字符串在s1中匹配到了
    while (x < n && y < m)
    {
        // 两个字符比较相等时都递增
        if (s1[x] == s2[y])
        {
            x++;
            y++;
        }
        else if (y == 0)
        {
            x++; // y跳回到开头，从x的下一个字符继续匹配
        }
        else
        {
            // 直到遇到不相等的字符
            y = next[y];
        }
    }
    // 当y指向最后时，找到了子字符串，否则没找到匹配的字符串，返回-1
    return y == m ? x - y : -1;
}

int main()
{
    char s1[] = "aabaabaafa";
    char s2[] = "aabaaf";
    int index = kmp(s1, s2);
    printf("s2在s1中匹配的开头索引为：%d", index);
}