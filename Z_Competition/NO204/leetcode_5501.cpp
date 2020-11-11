//          5501. 使陆地分离的最少天数
//
// 给你一个由若干 0 和 1 组成的二维网格 grid ，其中 0 表示水，而 1 表示陆地。岛屿由水平方向或竖直方向上相邻的 1 （陆地）连接形成。
// 如果 恰好只有一座岛屿 ，则认为陆地是 连通的 ；否则，陆地就是 分离的 。
// 一天内，可以将任何单个陆地单元（1）更改为水单元（0）。
// 返回使陆地分离的最少天数。
//
//
// 示例 1：
// 输入：grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
// 输出：2
// 解释：至少需要 2 天才能得到分离的陆地。
// 将陆地 grid[1][1] 和 grid[0][2] 更改为水，得到两个分离的岛屿。
//
// 示例 2：
// 输入：grid = [[1,1]]
// 输出：2
// 解释：如果网格中都是水，也认为是分离的 ([[1,1]] -> [[0,0]])，0 岛屿。
//
// 示例 3：
// 输入：grid = [[1,0,1,0]]
// 输出：0
//
// 示例 4：
// 输入：grid = [[1,1,0,1,1],
//              [1,1,1,1,1],
//              [1,1,0,1,1],
//              [1,1,0,1,1]]
// 输出：1
//
// 示例 5：
// 输入：grid = [[1,1,0,1,1],
//              [1,1,1,1,1],
//              [1,1,0,1,1],
//              [1,1,1,1,1]]
// 输出：2
//
// 提示：
// 1 <= grid.length, grid[i].length <= 30
// grid[i][j] 为 0 或 1

#include<bits/stdc++.h>
using namespace std;

// Medium


class Solution {
public:
    int n , m;
    vector<vector<int>>  g;
    vector<vector<bool>> st;                            // 判重数组
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(int x,int y)
    {
        st[x][y] = true;

        for(int i = 0; i < 4; ++i)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < m && !st[a][b] && g[a][b] ==1)
            {
                dfs(a,b);
            }
        }
    }

    // 判断连通块的数量
    bool check()
    {
        int cnt = 0;
        st = vector<vector<bool>>(n,vector<bool>(m,false));       // 每一次判重数组都清空

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(st[i][j] == false && g[i][j] == 1)
                {
                    cnt++;
                    dfs(i,j);        
                }
            }
        }

        if(cnt == 0)
        {
            return true;
        }
        return cnt > 1;
    }


    int minDays(vector<vector<int>>& grid)
    {
        this->n = grid.size();
        this->m = grid[0].size();
        this->g = grid;

        // 如果存在两个连通块就直接返回 0
        if(check())
        {
            return 0;
        }
        
        // 如果把其中的一个变为 0 其连通块变为两个那么直接返回 1
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(g[i][j] == 1)
                {
                    g[i][j] = 0;
                    if(check())
                    {
                        return 1;
                    }
                    else
                    {
                        g[i][j] = 1;
                    }
                }
            }
        }

        return 2;
    }
};