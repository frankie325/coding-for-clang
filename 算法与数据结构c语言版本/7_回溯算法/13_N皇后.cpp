#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：[["Q"]
*/

class Solution
{
private:
    vector<vector<string>> result; // 存放符合条件结果的集合
    vector<int> path;

public:
    // n 为输入的棋盘大小
    // row 是当前递归到棋盘的第几行了
    void backtracking(int n, int row, vector<string> &chessboard)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, chessboard, n)) // 验证合法就可以放
            {
                chessboard[row][col] = 'Q'; // 放置皇后
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.'; // 回溯
            }
        }
    }

    /*
    按照如下标准去重：
        不能同行
        不能同列
        不能同斜线 （45度和135度角）
    */
    bool isValid(int row, int col, vector<string> &chessboard, int n)
    {
        // 检查列
        for (int i = 0; i < row; i++)
        { // 这是一个剪枝
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }
        }
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        result.clear();
        // 初始化为.
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> result = s.solveNQueens(4);
    for (vector<vector<string>>::iterator it = result.begin(); it != result.end(); it++)
    {
        vector<string> str = *it;
        cout << "N皇后：";
        for (vector<string>::iterator vit = str.begin(); vit != str.end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}