//              51. N 皇后
//
// n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 上图为 8 皇后问题的一种解法。
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//
// 示例：
// 输入：4
// 输出：[
//  [".Q..",  // 解法 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // 解法 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// 解释: 4 皇后问题存在两个不同的解法。
//
//
// 提示：
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

#include<bits/stdc++.h>
using namespace std;

// Hard

class Solution {
private:
    bool isValid(int row, int col, vector<string>& chessboard, int n) 
    {
        int count = 0;

        // 检查列
        for (int i = 0; i < row; i++) 
        {
            if (chessboard[i][col] == 'Q') 
            {
                return false;
            }
        }

        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) 
        {
            if (chessboard[i][j] == 'Q') 
            {
                return false;
            }
        }

        // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
        {
            if (chessboard[i][j] == 'Q') 
            {
                return false;
            }
        }

        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> temp = vector<string>(n,string(n,'.'));


        function<void(int)> dfs = [&](int start) {
            if(start == n)
            {
                ans.push_back(temp);
                return;
            }
                int j = 0;
                
            for(; j < n; ++j)
            {
                if(isValid(start,j,temp,n))
                {
                    temp[start][j] = 'Q';
                    dfs(start+1);
                    temp[start][j] = '.';
                }
            }
        };

        dfs(0);

        return ans;
    }
};





int main()
{
    Solution s;
    auto arr = s.solveNQueens(4);
    for(auto& i : arr)
    {
        for(auto& j : i)
        {
            cout<<j<<endl;
        }
        cout<<"==============\n\n";
    }
    system("pause");
    return 0;
}