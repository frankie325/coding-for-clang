#include <stdio.h>

struct Stu
{
    char name[20];
    int age;
    float score;
};

int main()
{
    struct Stu s = {0};
    // struct Stu s = {"kfg", 25, 100};
    FILE *pf;
    pf = fopen("test.dat", "rb"); //二进制读模式
    // pf = fopen("test.dat", "wb"); // 二进制写模式
    if (pf == NULL)
    {
        printf("文件打开失败.\n");
        return 0;
    }
    // 读文件
    // 第一个参数：指向要写入的数据的指针
    // 第二个参数：每个数据单元的大小（以字节为单位）
    // 第三个参数：要写入的数据单元的数量
    // 第四个参数：文件指针
    fread(&s, sizeof(struct Stu), 1, pf);
    printf("%s %d %f", s.name, s.age, s.score);
    // 写文件 fwrite和fread参数一样
    // fwrite(&s, sizeof(struct Stu), 1, pf);

    fclose(pf);
    pf = NULL;
    return 0;
}