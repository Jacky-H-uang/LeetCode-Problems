// 给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。
//
//
// 示例 1：
// 输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：9
//
// 示例 2：
// 输入：grid = [[1,1,0,0]]
// 输出：1
//
//
// 提示：
// 1 <= grid.length <= 100
// 1 <= grid[0].length <= 100
// grid[i][j] 为 0 或 1


#include<bits/stdc++.h>
using namespace std;

// Medium


//  0   0   0   0
//  0   1   1   1
//  0   1   0   1
//  0   1   1   1   

// 找到 "边界" 全为 1

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(2)));
        
        // dp[i][j][0] 表示左边连续 1 的个数
        // dp[i][j][1] 表示右边连续 1 的个数
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(grid[i-1][j-1] == 1)
                {
                    dp[i][j][0] = 1 + dp[i][j-1][0];
                    dp[i][j][1] = 1 + dp[i-1][j][1];
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int side = min(dp[i][j][0],dp[i][j][1]); side > 0; side--)
                {
                    if(dp[i][j-side+1][1] >= side && dp[i-side+1][j][0] >= side)
                    {
                        ans = max(ans,side);
                        break;
                    }
                }
            }
        }
        return ans*ans;
    }
};