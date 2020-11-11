// 给定一个整数矩阵，找出最长递增路径的长度。
// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
//
//
// 示例 1:
// 输入: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// 输出: 4 
// 解释: 最长递增路径为 [1, 2, 6, 9]。
//
//
// 示例 2:
// 输入: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// 输出: 4 
// 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。


#include<bits/stdc++.h>
using namespace std;

// Hard


// 记忆化的深度优先搜索
// 矩阵看成有向图，然后在有向图中找最长路径
// 使用记忆化深度优先搜索，当访问到一个单元格 (i,j)(i,j) 时，如果 memo[i][j] != 0，说明该单元格的结果已经计算过，则直接从缓存中读取结果，
// 如果 memo[i][j] = 0，说明该单元格的结果尚未被计算过，则进行搜索，并将计算得到的结果存入缓存中。
 
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, columns;

    int dfs(vector<vector<int>>& matrix, int row, int column, vector<vector<int>>& memo) 
    {
        if (memo[row][column] != 0) 
        {
            return memo[row][column];
        }
        ++memo[row][column];
        for (int i = 0; i < 4; ++i) 
        {
            int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) 
            {
                memo[row][column] = max(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
            }
        }
        return memo[row][column];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        rows = matrix.size();
        columns = matrix[0].size();
        auto memo = vector<vector<int>> (rows, vector<int>(columns));
        int ans = 0;
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < columns; ++j) 
            {
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }
};