#include <stdio.h>

struct Student
{
    int id; // 学号
    char name[20];
    float score[3];
    float avg; // 平均成绩
};

void Input(struct Student *p)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter student %d info (id name score1 score2 score3):\n", i + 1);
        // 输入学生信息
        scanf("%d %s %f %f %f", &(p[i].id), p[i].name, &(p[i].score[0]), &(p[i].score[1]), &(p[i].score[2]));
        p[i].avg = (p[i].score[0] + p[i].score[1] + p[i].score[2]) / 3;
    }
}
struct Student Max(struct Student s[])
{
    int max = 0;
    for (int i = 1; i < 3; i++)
    {
        if (s[i].avg > s[max].avg)
        {
            max = i;
        }
    }
    // max记录的为平均成绩最大的学生索引
    return s[max];
}

int main()
{
    struct Student s[3]; // 三个学生
    struct Student *ps = s;
    // 传递指向结构体的指针
    Input(ps); // 输入三个学生的信息
    // 传递结构体地址
    struct Student maxStu = Max(s); // 寻找平均成绩最大的学生
    printf("The largest avg of student is %s", maxStu.name);
    return 0;
}