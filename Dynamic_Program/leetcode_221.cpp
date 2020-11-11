// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
//
// Input: 
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4

#include<iostream>
#include<vector>
using namespace std;

//Medium

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1));
        int l = 0;
        if(len1<1)
        {
            return 0;
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    l = max(l,dp[i][j]);
                }
            }
        }
        return l*l;
    }
};