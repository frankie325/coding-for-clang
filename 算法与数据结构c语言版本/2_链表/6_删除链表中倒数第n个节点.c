#include <stdio.h>
#include <stdlib.h>
#include "./statement.h"

/**
 * @description: 删除链表中倒数第n个节点
 */
ListNode *remove_node_from_end(ListNode *head, int n)
{

    /*
        快慢指针法：
        virtual_head->1->2->3->4->5->NULL
            |
        fast/slow
        假设删除倒数第二个节点：4

        1. 快指针先移动n步
        virtual_head->1->2->3->4->5->NULL
            |            |
           slow         fast

        2. 快慢指针同时移动，快指针移动到末尾，慢指针指向的节点就是要删除的节点
        virtual_head->1->2->3->4->5->NULL
                               |      |
                              slow   fast

     */
    ListNode *virtual_node = (ListNode *)malloc(sizeof(ListNode *)); // 头部虚拟节点
    virtual_node->next = head;
    ListNode *fast = virtual_node;
    ListNode *slow = virtual_node;

    while (n--)
    {
        fast = fast->next;
    }
    fast = fast->next; // 快指针多走一步，因为需要让slow指向删除节点的上一个节点

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return virtual_node->next;
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
    p5->next = NULL;

    struct ListNode *cur = remove_node_from_end(head, 2);

    while (cur)
    {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
    return 0;
}