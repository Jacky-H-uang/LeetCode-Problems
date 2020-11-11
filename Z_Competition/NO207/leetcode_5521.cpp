//              5521. 矩阵的最大非负积
//
// 给你一个大小为 rows x cols 的矩阵 grid 。最初，你位于左上角 (0, 0) ，每一步，你可以在矩阵中 向右 或 向下 移动。
// 在从左上角 (0, 0) 开始到右下角 (rows - 1, cols - 1) 结束的所有路径中，找出具有 最大非负积 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。
// 返回 最大非负积 对 109 + 7 取余 的结果。如果最大积为负数，则返回 -1 。
// 注意，取余是在得到最大积之后执行的。
//
//
// 示例 1：
// 输入：grid = [[-1,-2,-3],
//              [-2,-3,-3],
//              [-3,-3,-2]]
// 输出：-1
// 解释：从 (0, 0) 到 (2, 2) 的路径中无法得到非负积，所以返回 -1
//
// 示例 2：
// 输入：grid = [[1,-2,1],
//              [1,-2,1],
//              [3,-4,1]]
// 输出：8
// 解释：最大非负积对应的路径已经用粗体标出 (1 * 1 * -2 * -4 * 1 = 8)
//
// 示例 3：
// 输入：grid = [[1, 3],
//              [0,-4]]
// 输出：0
// 解释：最大非负积对应的路径已经用粗体标出 (1 * 0 * -4 = 0)
//
// 示例 4：
// 输入：grid = [[ 1, 4,4,0],
//              [-2, 0,0,1],
//              [ 1,-1,1,1]]
// 输出：2
// 解释：最大非负积对应的路径已经用粗体标出 (1 * -2 * 1 * -1 * 1 * 1 = 2)
//
//
// 提示：
// 1 <= rows, cols <= 15
// -4 <= grid[i][j] <= 4

#include<bits/stdc++.h>
using namespace std;

// Medium

// 三维的动态规划不能只记录正的，
// 要记录全部 包括最大值与最小值
// dp[i][j][0] 记录最大值
// dp[i][j][1] 记录最小值

#define LL long long

class Solution {
public:
    int MOD = 1000000007;
    int maxProductPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<LL>>> dp;                      // 注意开 LL 的数组
        dp.resize(m,vector<vector<LL>>(n,vector<LL>(2)));

        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];

        // Boudary 初始化：
        for(int i = 1; i < m; ++i)
        {
            // 初始化行
            dp[i][0][0] = dp[i-1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i-1][0][1] * grid[i][0];
        }
        for(int i = 1; i < n; ++i)
        {
            // 初始化列
            dp[0][i][0] = dp[0][i-1][0] * grid[0][i];
            dp[0][i][1] = dp[0][i-1][1] * grid[0][i];
        }

        //
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                LL a = dp[i-1][j][0] * grid[i][j];
                LL b = dp[i-1][j][1] * grid[i][j];
                LL c = dp[i][j-1][0] * grid[i][j];
                LL d = dp[i][j-1][1] * grid[i][j];

                // 状态转移方程 ： 
                // dp[i][j][0] = MAX{ dp[i-1][j][0] * grid[i][j] , dp[i-1][j][1] * grid[i][j] , dp[i][j-1][0] * grid[i][j] , dp[i][j-1][1] * grid[i][j]}
                // dp[i][j][1] = MIN{ dp[i-1][j][0] * grid[i][j] , dp[i-1][j][1] * grid[i][j] , dp[i][j-1][0] * grid[i][j] , dp[i][j-1][1] * grid[i][j]}
                dp[i][j][0] = max(max(max(a,b),c),d);
                dp[i][j][1] = min(min(min(a,b),c),d);
            }
        }

        return max(dp[m-1][n-1][0],dp[m-1][n-1][1]) % MOD >= 0? max(dp[m-1][n-1][0],dp[m-1][n-1][1]) % MOD:-1;
    }
};