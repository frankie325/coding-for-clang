#include <stdio.h>

int main()
{
    FILE *pf;
    pf = fopen("text.txt", "r"); // 读模式
    // pf = fopen("test.dat", "wb"); // 写模式
    if (pf == NULL)
    {
        printf("文件打开失败.\n");
        return 0;
    }
    // 随机读写
    /*
    定位文件指针：
    int fseek(FILE *stream, long offset, int whence);
    stream：指向文件的指针。
    offset：相对于whence的位置偏移量，以字节为单位。
    whence：定位的起始位置，可以是以下三个常量之一：
        SEEK_SET：文件开头
        SEEK_CUR：当前位置
        SEEK_END：文件末尾
    */
    // 文件字符串是‘hello world’
    fseek(pf, 4, SEEK_CUR);
    // 读取
    int ch = fgetc(pf);
    printf("%c\n", ch);      // 输出：o
    fseek(pf, -4, SEEK_CUR); // 文件字符串是‘hello world’
    ch = fgetc(pf);
    printf("%c\n", ch); // 输出：e

    // ftell输出当前位置距离文件开始的字节数，返回类型为long
    printf("%ld\n", ftell(pf));
    fclose(pf);
    pf = NULL;
    return 0;
}