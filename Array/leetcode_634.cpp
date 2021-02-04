//                              643. 子数组最大平均数 I
//
// 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
//
// 示例：
// 输入：[1,12,-5,-6,50,3], k = 4
// 输出：12.75
// 解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
//
// 提示：
// 1 <= k <= n <= 30,000。
// 所给数据范围 [-10,000，10,000]。


#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int p1 = 0;
        int p2 = k;
        double ans = accumulate(nums.begin() + p1 , nums.begin() + p2 , 0) * 1.0 / k;
        double cur = ans;
        while(p1 < n && p2 < n) {
            cur = (cur * k - nums[p1] + nums[p2]) / k;
            ans = max(ans, cur);
            ++p1;
            ++p2;
        }

        return ans;
    }
};