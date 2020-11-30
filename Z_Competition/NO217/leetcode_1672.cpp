#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(int i = 0; i < accounts.size(); ++i) {
            int cnt = 0;
            for(auto& x : accounts[i]) {
                cnt += x;
            }
            ans = max(ans,cnt);
        }

        return ans;
    }
};