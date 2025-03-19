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

/*
方法一：指针标记法
就是要处理的节点放入栈之后，紧接着放入一个空指针作为标记。这种方法可以叫做空指针标记法。
*/
class Solution
{
public:
    vector<int> traverse(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur;
        st.push(root);
        while (!st.empty())
        {
            cur = st.top();
            if (cur != NULL)
            {
                st.pop();
                // *先序遍历：5 4 1 2 6 7 8
                //  [6,4,5,NULL] -> 处理5 -> [6,4]
                //  [6,2,1,4,NULL] -> 处理4 -> [6,2,1]
                //  [6,2,1,NULL] -> 处理1 -> [6,2]
                //  [6,2,NULL]-> 处理2 ->[6]
                //  [8,7,6,NULL] -> 处理6 -> [8,7]
                //  [8,7,NULL] -> 处理7 -> [8]
                //  [8,NULL] -> 处理8 -> []
                if (cur->right)
                    st.push(cur->right); // 右节点
                if (cur->left)
                    st.push(cur->left); // 左节点
                st.push(cur);           // 中
                st.push(NULL); //下一轮要处理哪个节点，就会添加NULL标记

                // *中序遍历
                // if (cur->right)
                //     st.push(cur->right); // 右节点
                // st.push(cur); // 中
                // st.push(NULL);
                // if (cur->left)
                //     st.push(cur->left); // 左节点

                // *后序遍历
                // st.push(cur); // 中
                // st.push(NULL);
                // if (cur->right)
                //     st.push(cur->right); // 右节点
                // if (cur->left)
                //     st.push(cur->left); // 左节点
            }
            else
            {
                st.pop(); // 把NULL标记先弹出栈
                cur = st.top();
                result.push_back(cur->val); // 处理节点
                st.pop();                   // 处理完节点后，弹出栈
            }
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

    vector<int> result;
    Solution s;
    // result = s.preorderTraverse(&root);
    // result = s.inorderTraversal(&root);
    result = s.traverse(&root);

    for (auto &&i : result)
    {
        cout << i << endl;
    }
}