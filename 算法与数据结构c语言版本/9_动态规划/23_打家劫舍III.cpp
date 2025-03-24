#include <iostream>
#include <vector>
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
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额
*/

class Solution
{
public:
    int rob(TreeNode *root)
    {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    };
    // 树形dp
    vector<int> robTree(TreeNode *node)
    {
        // 递归终止条件，空节点设为0
        if (node == NULL)
            return {0, 0};

        // 1.确定dp数组的含义：dp数组包含两个元素
        //  dp[0]表示不偷当前节点的最大金额
        //  dp[1]表示偷当前节点的最大金额

        // 不偷左节点和偷左节点的最大金额
        vector<int> leftDp = robTree(node->left);
        // 不偷右节点和偷右节点的最大金额
        vector<int> rightDp = robTree(node->right);

        // 2.递推公式：
        // 偷当前节点，那就不能偷左右节点
        int val1 = leftDp[0] + rightDp[0] + node->val;
        // 不偷当前节点，那就可以偷左右节点
        int val2 = max(leftDp[0], leftDp[1]) + max(rightDp[0], rightDp[1]);

        return {val2, val1};
    }
};

int main()
{
    TreeNode root(3);
    TreeNode four(2);
    TreeNode six(3);
    // TreeNode one(1);
    TreeNode two(3);
    // TreeNode seven(2);
    TreeNode eight(1);
    root.left = &four;
    root.right = &six;
    // four.left = &one;
    four.right = &two;
    // six.left = &seven;
    six.right = &eight;

    Solution s;
    int result = s.rob(root);
    cout << "结果为：" << result << endl;
    return 0;
}