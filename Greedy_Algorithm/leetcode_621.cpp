#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        int len = tasks.size();

        for(auto& t : tasks) {
            cnt[t -'A'] ++;
        }

        sort(cnt.begin(),cnt.end(),greater<int>());
        int maxC = cnt[0];

        // 算出至少需要多少次
        int ans = (maxC - 1) * (n + 1) + 1;

        // 没遇到一个与 maxC 相同的就加1
        int i = 1;
        while(i < cnt.size() && cnt[i] == maxC) {
            ans++;
            i++;
        }

        return max(ans,len);
    }
};