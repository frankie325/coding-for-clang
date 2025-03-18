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
二叉树递归三部曲：
1.确定递归函数的参数和返回值： 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数， 并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
2.确定终止条件： 写完了递归算法, 运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。
3.确定单层递归的逻辑： 确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。
*/
void traverse(TreeNode *cur, vector<int> &vec)
{
    if (cur == NULL)
        return;

    // 前序遍历：中左右
    // vec.push_back(cur.val);
    // traverse(cur.left, vec);
    // traverse(cur.right, vec);

    // 中序遍历：左中右
    // traverse(cur.left, vec);
    // vec.push_back(cur.val);
    // traverse(cur.right, vec);

    // 后序遍历：左右中
    traverse(cur->left, vec);
    traverse(cur->right, vec);
    vec.push_back(cur->val);
}

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

    vector<int> v;
    traverse(&root, v);

    for (auto &&i : v)
    {
        cout << i << endl;
    }
}