#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> st;
        int ans = 0;
        for(auto& n : nums) {
            if(st[k-n] > 0) {
                st[k-n]--;
                ans++;
            }
            else {
                st[n]++;
            }
        }

        return ans;
    }
};