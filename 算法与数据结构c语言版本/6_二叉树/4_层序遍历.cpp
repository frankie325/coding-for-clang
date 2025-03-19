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
public:
    /*
    层序遍历:
        层序遍历一个二叉树。就是从左到右一层一层的去遍历二叉树。这种遍历的方式和我们之前讲过的都不太一样。
        需要借用一个辅助数据结构即队列来实现，队列先进先出，符合一层一层遍历的逻辑，而用栈先进后出适合模拟深度优先遍历也就是递归的逻辑。
        而这种层序遍历方式就是图论中的广度优先遍历，只不过我们应用在二叉树上
    */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> result;
        if (root != NULL)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> v;
            // 遍历每一层，推入数组中
            while (size--)
            {
                TreeNode *node = que.front();
                que.pop();
                v.push_back(node->val);
                // 将子节点推入队列，将进入下一轮循环
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(v);
        }
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

    vector<vector<int>> result;
    Solution s;
    result = s.levelOrder(&root);

    for (auto &&v : result)
    {
        for (auto &&i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}