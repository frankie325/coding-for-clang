#include <stdio.h>
#include <stdlib.h>
#include "./statement.h"
/*
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/

/*
    双指针法：
    pre: 初始指向NULL
    cur: 初始指向head
*/
struct ListNode *reverseNode(struct ListNode *head)
{
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    struct ListNode *temp;
    while (cur)
    {
        temp = cur->next;
        cur->next = pre; // *改变next指向前一个节点
        pre = cur;
        cur = temp;
    }
    return pre; // 反转完后pre为新的头指针
}

/*
    递归法：和双指针法思路一样
*/
struct ListNode *reverseDeep(struct ListNode *cur, struct ListNode *pre)
{
    if (cur == NULL)
        return pre;
    struct ListNode *temp = cur->next;
    cur->next = pre;
    return reverseDeep(temp, cur);
}

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

    // struct ListNode *cur = reverseNode(head);
    struct ListNode *cur = reverseDeep(head, NULL);

    while (cur)
    {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
}