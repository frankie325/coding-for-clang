#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct
{
    int size;
    struct Node *data; // 虚拟头节点
} MyLinkedList;

/**
 * @description: 创建链表
 */
MyLinkedList *createMyLinkedList()
{
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    // 创建一个虚拟头节点
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = (Node *)0; // 0也表示空指针 即NULL，(Node *)0为强制类型转换
    obj->data = head;
    obj->size = 0;
    return obj; // obj相当于是虚拟头结点
}

/**
 * @description: 获取链表中第index个节点的值，如果索引无效，则返回-1
 * @param {MyLinkedList} *obj
 * @param {int} index 0指向头结点
 */
int MyLinkedListGet(MyLinkedList *obj, int index)
{
    if (obj->size < 0 || index >= obj->size)
        return -1;

    Node *cur = obj->data->next; // cur指向头结点
    while (index)                // 如果index = 0时，直接跳过循环
    {
        cur = cur->next;
        index--;
    }
    return cur->val;
}

/**
 * @description: 往链表头部前添加一个元素
 */
void MyLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    /*
        !下面的顺序不能颠倒
        1.先将新节点的next指向原来的头节点
        2.再将头节点指向新节点
    */
    newNode->next = obj->data->next;
    obj->data->next = newNode;
    obj->size++;
}

/**
 * @description: 往链表尾部添加一个元素
 */
void MyLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    Node *cur = obj->data;
    while (cur->next) // *找到最后一个节点，cur->next为空时，说明cur指向最后一个节点
    {
        cur = cur->next;
    }
    cur->next = newNode;
    obj->size++;
}

/**
 * @description: 在链表中的第index个节点之前添加一个值为val的节点。如果index等于链表的长度，则该节点将附加到链表的末尾。
 */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index > obj->size)
        return;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;

    Node *cur = obj->data;
    while (index)
    {
        cur = cur->next;
        index--;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    obj->size++;
}

/**
 * @description: 删除指定索引的节点
 */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (obj->size < 0 || index >= obj->size)
        return;
    Node *cur = obj->data;
    while (index)
    {
        cur = cur->next;
        index--;
    }
    Node *temp = cur->next;
    cur->next = temp->next;
    free(temp);
    obj->size--;
}

int main()
{
    MyLinkedList *obj = createMyLinkedList();
    MyLinkedListAddAtHead(obj, 1);
    MyLinkedListAddAtHead(obj, 2);
    MyLinkedListAddAtHead(obj, 3);
    MyLinkedListAddAtHead(obj, 4);
    MyLinkedListAddAtHead(obj, 5);
    MyLinkedListAddAtTail(obj, 6);
    MyLinkedListAddAtTail(obj, 7);
    MyLinkedListAddAtTail(obj, 8);
    MyLinkedListAddAtTail(obj, 9);
    MyLinkedListAddAtTail(obj, 10);
    myLinkedListAddAtIndex(obj, 10, 11);
    myLinkedListDeleteAtIndex(obj, 10);
    printf("%d\n", MyLinkedListGet(obj, 0));
    printf("%d\n", MyLinkedListGet(obj, 1));
    printf("%d\n", MyLinkedListGet(obj, 2));
    printf("%d\n", MyLinkedListGet(obj, 3));
    printf("%d\n", MyLinkedListGet(obj, 4));
    printf("%d\n", MyLinkedListGet(obj, 5));
    printf("%d\n", MyLinkedListGet(obj, 6));
    printf("%d\n", MyLinkedListGet(obj, 7));
    printf("%d\n", MyLinkedListGet(obj, 8));
    printf("%d\n", MyLinkedListGet(obj, 9));
    printf("%d\n", MyLinkedListGet(obj, 10));

    return 0;
}