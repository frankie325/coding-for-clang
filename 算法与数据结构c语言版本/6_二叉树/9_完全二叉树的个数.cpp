#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 二叉树结构的定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num) : val(num), left(NULL), right(NULL) {}
};

/*
给出一个完全二叉树，求出该树的节点个数。

示例 1：

输入：root = [1,2,3,4,5,6]
输出：6
示例 2：

输入：root = []
输出：0
示例 3：

输入：root = [1]
输出：1
*/
class Solution
{
    /*
    方法一：普通遍历求总数

    方法二：判断左右节点是不是满二叉树，用公式2^k - 1
    */
public:
    int countNodes(TreeNode *node)
    {
        // 终止条件：叶子结点指向NULL为0
        if (node == NULL)
            return 0;
        // 开始根据左深度和右深度是否相同来判断该子树是不是满二叉树
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        int leftDepth = 0;
        int rightDepth = 0;
        while (left) // 求左子树深度
        {
            left = left->left;
            leftDepth++;
        }

        while (right) // 求右子树深度
        {
            right = right->right;
            rightDepth++;
        }

        // *如果最左最右深度相等，则说明是一个满二叉树
        if (leftDepth == rightDepth)
        {
            return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
        }
        int leftNums = countNodes(node->left);
        int rightNums = countNodes(node->right);
        return 1 + leftNums + rightNums;
    }
};

int main()
{
    TreeNode root(5);
    TreeNode four(4);
    TreeNode six(6);
    TreeNode one(1);
    TreeNode two(2);
    TreeNode seven(7);
    TreeNode eight(8);
    root.left = &four;
    root.right = &six;
    four.left = &one;
    four.right = &two;
    six.left = &seven;
    six.right = &eight;

    Solution s;
    int result = s.countNodes(&root);
    cout << "输出：" << result << endl;
}