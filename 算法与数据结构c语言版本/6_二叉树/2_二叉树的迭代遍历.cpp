#include <iostream>
#include <vector>
#include <stack>
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
    前序遍历:
    前序遍历是中左右，每次先处理的是中间节点，那么先将根节点放入栈中，
    然后将右孩子加入栈，再加入左孩子。
    */
    vector<int> preorderTraverse(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        st.push(root);
        TreeNode *cur;
        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            // 右节点先入栈
            if (cur->right)
                st.push(cur->right);
            // 左节点后入栈，下一轮出栈
            if (cur->left)
                st.push(cur->left);
        }
        return result;
    }

    /*
    中序遍历：
    遍历顺序和节点处理顺序不一致
    */
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        st.push(root);
        TreeNode *cur = root;

        while (!st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                // 左节点先入栈，直到碰到空节点
                cur = cur->left;
            }
            else
            {
                // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }

    /*
    后序遍历:
    再来看后序遍历，先序遍历是中左右，后序遍历是左右中，
    那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，
    然后再反转result数组，输出的结果顺序就是左右中了
    */
    vector<int> postorderTraverse(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        st.push(root);
        TreeNode *cur;
        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            // 左节点先入栈
            if (cur->left)
                st.push(cur->left);
            // 右节点后入栈，下一轮出栈
            if (cur->right)
                st.push(cur->right);
        }
        // 此时数组元素为中右左，再反转数组即可得到左右中
        reverse(result.begin(), result.end());
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

    vector<int> result;
    Solution s;
    // result = s.preorderTraverse(&root);
    // result = s.inorderTraversal(&root);
    result = s.postorderTraverse(&root);

    for (auto &&i : result)
    {
        cout << i << endl;
    }
}