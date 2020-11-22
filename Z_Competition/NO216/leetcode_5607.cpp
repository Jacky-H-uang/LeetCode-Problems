#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    // 前缀和
    int waysToMakeFair(vector<int>& a) {
        int n = a.size();
        vector<int> b(n + 1);
        vector<int> c(n + 1);
        for (int i = 0; i < n; ++i) 
        {
            b[i + 1] = a[i] - b[i];
            c[i + 1] = a[n - 1 - i] - c[i];
        }
        int results = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (b[i] == c[n - 1 - i])       ++results;
        }
        return results;
    }
};