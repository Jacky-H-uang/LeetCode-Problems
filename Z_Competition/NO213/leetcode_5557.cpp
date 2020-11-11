#include<bits/stdc++.h>
using namespace std;

// Hard


class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int h = destination[1];
        int v = destination[0];

        // 计算组合数
        vector<vector<int>> comb(h + v, vector<int>(h));
        comb[0][0] = 1;
        for (int i = 1; i < h + v; ++i) 
        {
            comb[i][0] = 1;
            for (int j = 1; j <= i && j < h; ++j) 
            {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }
        
        string ans = "";
        int imax = h + v;
        for(int i = 0; i < imax; ++i)
        {
            if(h > 0) 
            {
                // 如果高位放置 H 
                int o = comb[h+v-1][h-1];
                if(k > o)
                {
                    ans += 'V';
                    --v;
                    k -= o;
                }
                else
                {
                    ans += 'H';
                    --h;
                }
            }
            else
            {
                ans += 'V';
                --v;
            }
        }

        return ans;
    }
};