#include <stdio.h>
#include <stdlib.h>
#include "./statement.h"

/*
5_两两交换链表中的节点:
输入: 1->2->3->4->5->NULL
输出: 2->1->4->3->5->NULL


virtual_head->1->2->3->4->5->NULL
      |
     !cur：cur指向的是两个要交换节点的前面一个节点

如果是奇数个节点：那么剩下的一个节点不用交换
*/
ListNode *swapNode(ListNode *head)
{
    ListNode *virtual_node = (ListNode *)malloc(sizeof(ListNode *)); // 头部虚拟节点
    virtual_node->next = head;
    ListNode *cur = virtual_node;

    // !循环终止条件：如果是奇数个，则cur->next->next为终止条件；如果是偶数个，则cur->next为终止条件；
    while (cur->next && cur->next->next)
    {
        // 下面以cur = virtual_head为例
        ListNode *temp = cur->next; // 临时记录节点1
        // ListNode *temp2 = cur->next;
        cur->next = cur->next->next;  // virtual_head指向节点2
        temp->next = cur->next->next; // 节点1指向节点3
        cur->next->next = temp;       // 节点2指向节点1
        cur = cur->next->next;        // 往下继续循环
    }
    head = virtual_node->next;
    free(virtual_node);
    return head;
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

    struct ListNode *cur = swapNode(head);

    while (cur)
    {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
}