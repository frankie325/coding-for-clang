#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void push_back(struct Node **ph, int i)
{
    // 使用malloc动态创建一个节点
    struct Node *pnew = (struct Node *)malloc(sizeof(struct Node));
    pnew->data = i;
    pnew->next = NULL;

    // 如果指定的节点为空（头指针），则直接赋值
    if (*ph == NULL)
    {
        *ph = pnew;
    }
    else
    {
        struct Node *tail = *ph;
        // 如果指定的节点不为空，则找到最后的节点，设置它的next指向新节点
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = pnew;
    }
}

void show_list(struct Node *h)
{

    while (h)
    {
        printf("%d->", h->data);
        h = h->next;
    }
}

void destroy_list(struct Node **ph)
{
    struct Node *cur = *ph;
    struct Node *next = cur->next;
    while (cur != NULL)
    {
        free(cur);
        cur = next;
        if (cur == NULL)
            break;
        next = cur->next;
    }
}

int main()
{
    // 在链表存储0-9这十个整数
    struct Node *head = NULL; // 创建头指针
    for (int i = 0; i < 10; i++)
    {
        // 创建新节点插入到最后的位置
        push_back(&head, i); // !注意这里传入的是head的地址，不然传递的是NULL指针
    }
    show_list(head);
    // 释放内存
    destroy_list(&head);
    printf("\n内存已释放");
    return 0;
}