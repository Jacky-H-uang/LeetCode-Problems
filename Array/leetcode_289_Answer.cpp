// 根据百度百科，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
// 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。
//
// 每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
// 1. 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
// 2. 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
// 3. 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
// 4. 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
// 根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。
// 下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
//
// 示例：
// 输入： 
// [
//   [0,1,0],
//   [0,0,1],
//   [1,1,1],
//   [0,0,0]
// ]
// 输出：
// [
//   [0,0,0],
//   [1,0,1],
//   [0,1,1],
//   [0,1,0]
// ]

#include<iostream>
#include<vector>
using namespace std;

//Medium
class Solution {
    int directions[8][2] = 
                {
                 {-1, -1}, 
                 {-1, 0}, 
                 {-1, 1},
                 {0, -1},
                 {0, 1},
                 {1, -1},
                 {1, 0},  
                 {1, 1}
               };
    int row;
    int col;
    int _isAlive(const vector<vector<int>> &board, const int &rowPos, const int &colPos) 
    {
        int aroundAlive = 0;
        for (int i = 0; i < 8; ++i) 
        {
            int x = rowPos + directions[i][0];
            int y = colPos + directions[i][1];
            if (x >= 0 && x < row && y >= 0 && y < col) 
            {
                if (board[x][y] & 1) aroundAlive++;
            }
        }
        return aroundAlive;
    }
    public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        row = board.size();
        if (!row) return;
        col = board[0].size();

        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j) {
                int numAlive = _isAlive(board,  i, j);
                int &alive = board[i][j];
                if (alive) 
                {
                    if (numAlive == 2 || numAlive == 3)
                        alive += 2;
                } 
                else 
                {
                    if (numAlive == 3)
                        {
                            alive += 2;
                        }
                }
            }
        for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    board[i][j] /=  2;
                }
            }
    }
};