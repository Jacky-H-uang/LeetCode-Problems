#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// binary search 优化
class Solution {
public:
    int maxProfit(vector<int>& v, int orders) {  
        int l = 1, r = 1;
        for (int i : v)     r = max(i, r);

        while (l < r) 
        {
            int mid = (l + r) / 2;
            long long s = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] >= mid)    s += (v[i] - mid + 1);
            }
            if (s <= orders)    r = mid;
            else                l = mid + 1;
        }
        long long ans = 0;
        int sur = orders;
        for (int i = 0; i < v.size(); i++) 
        {
            if (v[i] >= l)
            {
                sur -= (v[i] - l + 1);
                long long first = l, last = v[i], num = v[i] - l + 1;
                (ans += ((first + last) * num / 2) % MOD) %= MOD;
            }
        }

        // 处理 负的 sur
        (ans += (long long)sur * (l - 1) % MOD) %= MOD;
        
        return (int)ans;
    }
};