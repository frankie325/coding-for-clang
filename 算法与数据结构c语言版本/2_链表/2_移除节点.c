#include <stdio.h>
#include <stdlib.h>

/*
移除链表节点：
这里就涉及如下链表操作的两种方式：
*/

// *1.直接使用原来的链表来进行删除操作。
struct ListNode *remove_node(struct ListNode *head, int val)
{
    struct ListNode *temp;
    // !移除头结点和移除其他节点的操作是不一样的：移除头指针时，将头指针指向下一个节点即可
    // !移除其他节点都是通过前一个节点来移除当前节点，而头结点没有前一个节点
    while (head && head->val == val) // 使用while循环，因为可能有多个节点的值都是一样的 如 1->1->1->2->3
    {
        temp = head;
        head = head->next;
        free(temp); // 释放内存
    }

    struct ListNode *cur = head;
    // 此解法需要判断cur存在因为cur指向head，如果head为NULL，cur也为NULL
    while (cur && cur->next)
    {
        if (cur->next->val == val) // 如果下一个节点的值等于val
        {
            temp = cur->next;
            cur->next = cur->next->next; // 移除下一个节点
            free(temp);
        }
        else
        {
            cur = cur->next; // 移动到下一个节点
        }
    }

    return head;
}

// *2.设置一个虚拟头结点在进行删除操作: 统一了删除操作，不需要单独处理头结点的情况。
struct ListNode *remove_node_by_virtual_head(struct ListNode *head, int val)
{
    typedef struct ListNode LN;
    LN *temp;
    LN *virtual_head = (LN *)malloc(sizeof(LN));
    virtual_head->next = head; // 虚拟头结点指向头结点

    LN *cur = virtual_head;
    while (cur && cur->next)
    {
        if (cur->next->val == val) // 如果下一个节点的值等于val
        {
            temp = cur->next;
            cur->next = cur->next->next; // 移除下一个节点
            free(temp);
        }
        else
        {
            cur = cur->next; // 移动到下一个节点
        }
    }
    head = virtual_head->next; // 虚拟头结点指向的下一个节点即为新的头结点
    free(virtual_head); // 释放虚拟头结点
    return head;
}

// void remove_node2(struct ListNode *head, int val)
// {
//     struct ListNode *temp;
//     while (head && head->val == val)
//     {
//         temp = head;
//         *head = *(head->next); //传递头指针地址，直接修改头指针的指向
//     }

//     struct ListNode *cur;
//     cur = head;
//     while (cur && cur->next)
//     {
//         if (cur->next->val == val)
//         {
//             temp = cur->next;
//             cur->next = cur->next->next;
//         }
//         else
//         {
//             cur = cur->next;
//         }
//     }
// }