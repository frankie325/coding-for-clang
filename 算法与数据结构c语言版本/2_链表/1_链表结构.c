#include <stdio.h>
#include "./statement.h"
#include "./2_移除节点.c"

int main()
{
    struct ListNode *head = NULL;
    struct ListNode *p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p5 = (struct ListNode *)malloc(sizeof(struct ListNode));

    p1->val = 1;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;
    p5->val = 5;

    head = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = NULL;

    // head = remove_node(head, 1); // 移除头指针，指向新的头指针
    head = remove_node_by_virtual_head(head, 1); // 通过虚拟头结点移除头指针，指向新的头指针
    // 打印链表
    struct ListNode *p = head;
    while (p)
    {
        printf("%d\n", p->val);
        p = p->next;
    }

    return 0;
}

// int main()
// {
//     int n;
//     struct ListNode p5 = {5, NULL};
//     struct ListNode p4 = {4, &p5};
//     struct ListNode p3 = {3, &p4};
//     struct ListNode p2 = {2, &p3};
//     struct ListNode p1 = {1, &p2};
//     struct ListNode head = p1;

//     // 移除链表中的节点，传递头指针地址，不需要返回值，可在函数内直接修改头指针的指向
//     remove_node2(&head, 1);

//     struct ListNode *cur = &head;
//     while (cur)
//     {
//         printf("%d\n", cur->val);
//         cur = cur->next;
//     }
//     return 0;
// }