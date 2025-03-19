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

class Solution
{
private:
    void swap(TreeNode *node)
    {
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

public:
    /*
    翻转二叉树: 把每一个节点的左右孩子翻转一下，就可以达到整体翻转的效果
    */
    TreeNode *invertTree(TreeNode *node)
    {
        // 终止条件
        if (node == NULL)
            return node;
        // 按照先序遍历来交换节点
        // swap(node);              // 中
        // invertTree(node->left);  // 左
        // invertTree(node->right); // 右

        // 按照后序遍历来交换节点
        invertTree(node->left);  // 左
        invertTree(node->right); // 右
        swap(node);              // 中

        // 按照中序遍历来交换节点
        // !不能只是简单的把swap放到中间，因为中间交换后left到右边了，继续递归node->right其实还是左子树
        // invertTree(node->left);  // 左
        // swap(node);              // 中
        // invertTree(node->right); //error 右
        // invertTree(node->left); //应该继续递归node->left
        return node;
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

    vector<vector<int>> result;
    Solution s;
    TreeNode *root2 = s.invertTree(&root);
    cout << "翻转成功" << endl;
}