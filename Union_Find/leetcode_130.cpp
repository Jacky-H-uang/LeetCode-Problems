// 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
//
//
// 示例:
// X X X X
// X O O X
// X X O X
// X O X X
// 运行你的函数后，矩阵变为：
// X X X X
// X X X X
// X X X X
// X O X X
// 解释:
// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
// 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
// 如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。



#include<bits/stdc++.h>
using namespace std;

// Medium

//  X   X   1   X   1   X
//  X   O   X   X   X   1
//  X   O   X   O   X   X
//  X   X   O   X   1   X
//  X   X   X   X   1   X
//  1   1   1   X   1   X
//  X   X   X   X   1   X
//  1   X   1   X   1   X 


class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();

        // 空数组时候或者数组只有两行的时候直接返回 （因为此时要么为空要么只存在边界）
        if(m == 0)
        {
            return;
        }

        int n = board[0].size();

        // 深度搜索与边界 'O' 相连接的 'O'
        function<void(int,int)> dfs = [&](int x,int y) {
            // Boundary : 当边界为 'X' 的时候就退出搜索 为 'O' 的时候继续搜索与它相连接的 'O'
            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
            {
                return;
            }

            // 与边界相连接的 'O' 全部标记为 'A'
            board[x][y] = 'A';

            dfs(x,y+1);
            dfs(x+1,y);
            dfs(x-1,y);
            dfs(x,y-1);
        };

        function<void()> find = [&]() {
            // 从四个边界开始搜索
            for(int i = 0; i < m; ++i)
            {
                dfs(i,0);
                dfs(i,n-1);
            }
            for(int i = 0; i < n; ++i)
            {
                dfs(0,i);
                dfs(m-1,i);
            }

            // 将 '1' 全部还原为 'O' （因为这是与边界 'O' 相连接的）
            // 其余的全部置为 'X'
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    board[i][j] = board[i][j] == 'A'? 'O' : 'X';
                }
            }
        };

        find();
    }
};