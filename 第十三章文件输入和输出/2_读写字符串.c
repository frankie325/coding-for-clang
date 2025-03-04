#include <stdio.h>

int main()
{
    FILE *pf;
    pf = fopen("text.txt", "r");
    // pf = fopen("text.txt", "w");
    if (pf == NULL)
    {
        printf("文件打开失败.\n");
        return 0;
    }
    // 读文件
    char buf[100] = {0};
    // 第一个参数为存储输入位置地址，第二个参数表示读取的字符串大小，第三个参数是文件指针
    // fgets读取输入直到第一个换行符后面或者文件结尾
    fgets(buf, 100, pf);
    printf("%s", buf);
    fgets(buf, 100, pf);
    printf("%s", buf);
    // 写文件
    // fputs("hello world\n", pf);
    // fputs("hello bit\n", pf);

    // fgets保留了换行符，fputs就不会再自动添加换行符，配合使用非常好
    fclose(pf);
    pf = NULL;
    return 0;
}