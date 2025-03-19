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
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]
*/
class Solution
{
    /*
    方法一：普通遍历求总数

    方法二：判断左右节点是不是满二叉树，用公式2^k - 1
    */
public:
    int getHeight(TreeNode *node)
    {
        // 确定终止条件：
        if (node == NULL)
            return 0;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        // 如果左子树不是平衡树，往上抛-1
        if (leftHeight == -1)
            return -1;
        // 如果右子树不是平衡树，往上抛-1

        if (rightHeight == -1)
            return -1;

        // 如果左右子树高度差大于1，也往上抛-1
        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }
        else
        {
            return 1 + max(leftHeight, rightHeight);
        }
    }

    int isBalance(TreeNode *root)
    {
        // 如果根节点得到的值是-1，则不是平衡二叉树
        return getHeight(root) == -1 ? false : true;
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
    int result = s.isBalance(&root);
    cout << "输出：" << result << endl;
}