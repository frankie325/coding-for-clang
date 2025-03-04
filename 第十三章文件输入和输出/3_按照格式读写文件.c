#include <stdio.h>

struct Stu
{
    char name[20];
    int age;
    float score;
};

int main()
{
    struct Stu s = {"kfg", 25, 100};
    FILE *pf;
    pf = fopen("text.txt", "r");
    // pf = fopen("text.txt", "w");
    if (pf == NULL)
    {
        printf("文件打开失败.\n");
        return 0;
    }
    // 读文件 fscanf与scanf只有第一个参数不同，第一个参数为输入的文件指针
    fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
    printf("%s %d %f", s.name, s.age, s.score);
    // 写文件 fprintf与printf只有第一个参数不同，第一个参数为输入的文件指针
    // fprintf(pf, "%s %d %f", s.name, s.age, s.score);

    fclose(pf);
    pf = NULL;
    return 0;
}