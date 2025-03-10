
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;
// 头文件 声明
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

struct ListNode *remove_node_by_virtual_head(struct ListNode *head, int val);
struct ListNode *remove_node(struct ListNode *head, int val);
void remove_node2(struct ListNode *head, int val);