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

       3          3 最高高度即时最深深度
    9     20      2
        15   7    1
                  0
返回它的最大深度 3。
*/
class Solution
{

    /*
    本题可以使用前序（中左右），也可以使用后序遍历（左右中），使用前序求的就是深度，使用后序求的是高度。

    二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）
    二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数或者节点数（取决于高度从0开始还是从1开始）
    */
public:
    int getDepth(TreeNode *node)
    {
        // 终止条件：叶子结点指向NULL为0
        if (node == NULL)
            return 0;

        int leftDepth = getDepth(node->left);        // 左
        int rightDepth = getDepth(node->right);      // 右
        int result = 1 + max(leftDepth, rightDepth); // 中
        return result;
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
    int result = s.getDepth(&root);
    cout << "输出：" << result << endl;
}