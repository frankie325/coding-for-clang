#include <stdio.h>
int transfer()
{
    char ch = 0;
    scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
        printf("%c\n", ch);
        printf("%d\n", ch);
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - 32;
        printf("%c\n", ch);
        printf("%d\n", ch);
    }
    return 0;
}