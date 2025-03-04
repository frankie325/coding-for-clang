#include <stdio.h>

int main()
{

    // FILE是一个结构体类型，用于表示文件流
    FILE *pf;
    // 打开文件 "text.txt" 以读模式 ("r")
    pf = fopen("text.txt", "r");
    // 打开文件 "text.txt" 以写入模式 ("w")，把现有文件内容清空
    // pf = fopen("text.txt", "w");

    // 检查文件是否成功打开，文件打开失败则是一个空指针
    if (pf == NULL)
    {
        printf("文件打开失败.\n");
        return 0;
    }
    // 读文件 getc和fgetc一样
    int ch;
    ch = getc(pf); // 读取一个字符
    printf("读取的字符为：%c\n", ch);
    // 写数据 putc和fputc一样
    // putc('a', pf); // 把一个字符放入到FILE指针pf指定的文件中
    // putc('b', pf); // 把一个字符放入到FILE指针pf指定的文件中
    // putc('c', pf); // 把一个字符放入到FILE指针pf指定的文件中
    // putc('d', pf); // 把一个字符放入到FILE指针pf指定的文件中
    // 关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}