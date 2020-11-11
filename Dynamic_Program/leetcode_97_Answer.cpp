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
    // 滚动数组的优化
    bool isInterleave(string s1, string s2, string s3) 
    {
        auto f = vector <int> (s2.size() + 1, false);

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) 
        {
            return false;
        }

        f[0] = true;
        for (int i = 0; i <= n; ++i) 
        {
            for (int j = 0; j <= m; ++j) 
            {
                int p = i + j - 1;
                if (i > 0) 
                {
                    f[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) 
                {
                    f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[m];
    }
};