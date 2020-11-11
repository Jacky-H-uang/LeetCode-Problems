// 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
//
// 示例 1:
// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// 输出: true
//
// 示例 2:
// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// 输出: false



#include<bits/stdc++.h>
using namespace std;

// Hard
// 字符串的动态规划 难点。

class Solution {
public:
    // dp[i][j] 表示 s1[0~i-1] 和 s2[0~j-1] 能否交错形成 s3[0~i+j-1]
    bool isInterleave(string s1, string s2, string s3) 
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1 + len2 != len3)
        {
            return false;
        }
        vector<vector<bool>> dp(len1+1,vector<bool>(len2+1));
        dp[0][0] = true;
        for(int i=1;i<=len1;i++)
        {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for(int i=1;i<=len2;i++)
        {
            dp[0][i] = dp[0][i-1] && (s2[i-1] == s3[i-1]);
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]); 
            }
        }
        return dp[len1][len2];
    }
};