#include <stdio.h>

struct Student
{
    char name[20];
    int age;
    struct Student *next; // 指针，指向下一个结构体Student的地址
};

int main()
{
    /*
        链表结构图：
        head -> s1 -> s2 -> s3 -> NULL

        +-------------------+      +-------------------+      +-------------------+
        | struct Student s1 | ---> | struct Student s2 | ---> | struct Student s3 | ---> NULL
        +-------------------+      +-------------------+      +-------------------+
        | name: "张三"       |      | name: "李四"       |      | name: "王五"       |
        | age: 20           |      | age: 21           |      | age: 22           |
        | next: &s2         |      | next: &s3         |      | next: NULL        |
        +-------------------+      +-------------------+      +-------------------+
    */
    struct Student *head = NULL; // 头指针
    struct Student *cur = NULL;  // 当前指向的指针
    struct Student s1 = {"张三", 20};
    struct Student s2 = {"李四", 21};
    struct Student s3 = {"王五", 22};
    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;
    head = &s1;
    cur = head;
    while (cur != NULL)
    {
        printf("%s %d\n", cur->name, cur->age);
        cur = cur->next;
    }
    return 0;
}