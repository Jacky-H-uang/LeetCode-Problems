#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int n = s.size();
        int cnt = 1;
        int start = 0;
        int end = 1;
        for(int i = 1; i < n; ++i) {
            if(s[i] == s[i-1]) {
                cnt++;
                end++;
            }
            else {
                if(cnt >= 3) {
                    ans.push_back({start,end-1});
                }
                cnt = 1;
                start = end;
                end++;
            }
        }
        if(cnt >= 3) {
            ans.push_back({start,end-1});
        }

        return ans;
    }
};