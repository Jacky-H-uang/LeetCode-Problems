#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    // 贪心
    int minimumEffort(vector<vector<int>>& a) 
    {
        sort(a.begin(), a.end(), [&](const vector<int>& a, const vector<int>& b) 
        {
           return a[1] - a[0] > b[1] - b[0]; 
        });
        int results = 0;
        int total = 0;
        for (const auto& b : a) 
        {
            results = max(results, total + b[1]);
            total += b[0];
        }
        return results;
    }
};