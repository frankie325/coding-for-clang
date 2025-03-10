#include <stdio.h>
#include <stdlib.h>
#include "./statement.h"

/*

1.判断链表有环：
可以使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，
fast指针每次移动两个节点，slow指针每次移动一个节点，
如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。
2.如果有环，如何找到这个环的入口：查看代码随想录
 */

/**
 * @description:  给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回null。

 */
ListNode *detect_circle_entry(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next; // 快指针步长为2
        slow = slow->next;       // 慢指针步长为1
        if (fast == slow)        // 相遇点
        {
            // 相遇之后，设置一个指针从相遇点开始，设置一个指正从头指针开始，步长加一，当他们指向同一个节点时，则是环形的入口点
            ListNode *f = fast, *h = head;
            while (f != h)
            {
                f = f->next;
                h = h->next;
            }
            return h;
        }
    }
    return NULL; // 链表无环，返回NULL
}

int main()
{
    ListNode *head = NULL;
    ListNode *p1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p4 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p5 = (ListNode *)malloc(sizeof(ListNode));

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
    p5->next = p3; // p5->p3构成一个环

    struct ListNode *entry = detect_circle_entry(head);
    printf("入口点为：%d\n", entry->val);
    return 0;
}