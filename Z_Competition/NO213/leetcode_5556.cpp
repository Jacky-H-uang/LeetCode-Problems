#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    // 尽可能用完所有的砖块后再用梯子
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int sum = 0;            // 计算砖头的数量
        
        for(int i = 1; i < n; ++i)
        {
            if(heights[i-1] < heights[i])
            {
                int dif = heights[i] - heights[i-1];
                pq.push(dif);
                if(pq.size() > ladders)
                {
                    sum += pq.top();
                    pq.pop();
                }
            }
            if(sum > bricks)        return i-1;
        }

        return n-1;
    }
};