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
    对称二叉树：
         如果左子树的左节点和右子树的右节点相等，则是对称的

*/
class Solution
{

public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 首先排除空节点的情况
        if (left == NULL && right != NULL)
            return false;
        else if (left != NULL && right == NULL)
            return false;
        else if (left == NULL && right == NULL)
            return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val)
            return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right); // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left);  // 左子树：右、 右子树：左
        bool result = outside && inside;
        return result;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return compare(root->left, root->right);
    }
};

int main()
{
    TreeNode root(5);
    TreeNode four(4);
    TreeNode six(4);
    TreeNode one(1);
    TreeNode two(2);
    TreeNode seven(2);
    TreeNode eight(1);
    root.left = &four;
    root.right = &six;
    four.left = &one;
    four.right = &two;
    six.left = &seven;
    six.right = &eight;

    Solution s;
    bool result = s.isSymmetric(&root);
    cout << "输出：" << result << endl;
}