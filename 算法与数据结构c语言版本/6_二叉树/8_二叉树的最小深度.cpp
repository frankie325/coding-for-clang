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
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例： 给定二叉树

       3
     /   \
    9     20
         /  \
        15   7

返回它的最小深度 2.
*/

/*
!注意：最小深度是从根节点到最近叶子节点的最短路径上的节点数量。注意是叶子节点。
所以，如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度。
反之，右子树为空，左子树不为空，最小深度是 1 + 左子树的深度。 最后如果左右子树都不为空，返回左右子树深度最小值 + 1 。
*/
class Solution
{
public:
    int getMinDepth(TreeNode *node)
    {
        // 终止条件：叶子结点指向NULL为0
        if (node == NULL)
            return 0;

        int leftDepth = getMinDepth(node->left);   // 左
        int rightDepth = getMinDepth(node->right); // 右

        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == NULL && node->right != NULL)
        {
            return 1 + rightDepth;
        }
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != NULL && node->right == NULL)
        {
            return 1 + leftDepth;
        }
        return 1 + min(leftDepth, rightDepth);
    }
};

int main()
{
    TreeNode root(5);
    TreeNode four(4);
    TreeNode six(6);
    TreeNode one(1);
    TreeNode two(2);

    root.left = &four;
    root.right = &six;
    four.left = &one;
    four.right = &two;

    Solution s;
    int result = s.getMinDepth(&root);
    cout << "输出：" << result << endl;
}