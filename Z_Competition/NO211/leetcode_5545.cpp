#include<bits/stdc++.h>
using namespace std;

// Medium

// 排序后求最长上升子序列
// 先按年龄排序 然后求分数的最长上升子序列
struct player {
    int age;
    int scores;

};

bool cmp(player p1,player p2){
    return p1.age == p2.age? p1.scores < p2.scores : p1.age < p2.age;
}

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans = 0;
        int n = scores.size();
        vector<player> aux;
        vector<int> dp(n,0);
        for(int i = 0; i < n; ++i)
        {
            player p;
            p.age = ages[i];
            p.scores = scores[i];
            aux.push_back(p);
        }

        sort(aux.begin(),aux.end(),cmp);
        
        for(int i = 0; i < aux.size(); ++i)
        {
            dp[i] = aux[i].scores;
            for(int j = 0; j < i; ++j)
            {
                if(aux[j].scores <= aux[i].scores)          dp[i] = max(dp[i] , dp[j] + aux[i].scores);
            }
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};