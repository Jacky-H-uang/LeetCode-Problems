#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    void bfs(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    int cur = 4;
                    if(i > 0 && grid[i-1][j] == 1)          cur--;
                    if(i < n-1 && grid[i+1][j] == 1)        cur--;
                    if(j > 0 && grid[i][j-1] == 1)          cur--;
                    if(j < m-1 && grid[i][j+1] == 1)        cur--;
                    ans += cur;
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        bfs(grid);
        return ans;
    }
};