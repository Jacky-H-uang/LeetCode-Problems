#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    // f(i , j)     表示放置字符数量 i 且 后一个字符为元音 j 时候的情况
    // 状态转移方程：f(i , j) += sum{f(i-1 , k)}   (1<= k <= j)
    int f[101][101];

    int countVowelStrings(int n) 
    {
        for (int i = 1; i <= 5; i ++)   f[1][i] = 1;

        
        for (int i = 2; i <= n; ++i)                    // 枚举字符数量
            for (int j = 1; j <= 5; ++j)                // 枚举元音
                for (int k = 1; k <= j; ++k)
                    f[i][j] += f[i - 1][k];
        
        int ans = 0;
        
        for (int i = 1; i <= 5; i ++)   ans += f[n][i];
        
        return ans;
    }
};

