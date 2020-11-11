#include<bits/stdc++.h>
using namespace std;

// Hard

// Unoin-Find
class Solution {
public:
    int f[10000];
    
    int find(int x) {
        if (x == f[x]) return x;
        else return f[x] = find(f[x]);
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        for (int i = 1; i <= n; i++)    f[i] = i;

        // 只需要判断 大于等于 threshold + 1 ~ n 的连通性就行
        for (int i = threshold + 1; i <= n; ++i) 
        {
            int t = i;
            while (t + i <= n)
            {
                int p = find(t);
                int q = find(t + i);
                f[q] = p;               // 将两个连通
                t += i;
            }
        }

        vector<bool> ans;
        
        for (auto &x : queries) 
        {
            int p = find(x[0]);
            int q = find(x[1]);
            ans.push_back(p == q);
        }
        return ans;
    }
};