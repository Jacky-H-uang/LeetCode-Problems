#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        
        // 第 i 处第 j 条跑道的跳跃次数
        vector<vector<int>> dp(n,vector<int>(3,0x3f3f3f3f));
        dp[0][1] = 0;
        dp[0][0] = 1;
        dp[0][2] = 1;
        for(int i = 0; i < n; ++i) {
            // 不需要跳跃
            if(obstacles[i] != 1)       dp[i][0] = dp[i-1][0];
            if(obstacles[i] != 2)       dp[i][1] = dp[i-1][1];
            if(obstacles[i] != 3)       dp[i][2] = dp[i-1][2];
            
            // 需要跳跃
            if(obstacles[i] != 1)       dp[i][0] = min(dp[i][0] , min(dp[i][1],dp[i][2]) + 1);
            if(obstacles[i] != 2)       dp[i][1] = min(dp[i][1] , min(dp[i][0],dp[i][2]) + 1);
            if(obstacles[i] != 3)       dp[i][2] = min(dp[i][2] , min(dp[i][1],dp[i][0]) + 1);
        }

        return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    }
};