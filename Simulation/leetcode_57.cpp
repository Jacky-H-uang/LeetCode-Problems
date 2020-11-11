//                                              57. Insert Interval
//
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.
//
//
// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//
// Example 3:
// Input: intervals = [], newInterval = [5,7]
// Output: [[5,7]]
//
// Example 4:
// Input: intervals = [[1,5]], newInterval = [2,3]
// Output: [[1,5]]
//
// Example 5:
// Input: intervals = [[1,5]], newInterval = [2,7]
// Output: [[1,7]]
//
//
// Constraints:
// 0 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= intervals[i][0] <= intervals[i][1] <= 105
// intervals is sorted by intervals[i][0] in ascending order.
// newInterval.length == 2
// 0 <= newInterval[0] <= newInterval[1] <= 105


#include<bits/stdc++.h>
using namespace std;

// Hard

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) 
        {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) 
                {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) 
            {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else 
            {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) 
        {
            ans.push_back({left, right});
        }
        return ans;
    }
};