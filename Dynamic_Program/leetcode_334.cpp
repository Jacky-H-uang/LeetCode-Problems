// 给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
// 数学表达式如下:
// 如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
// 使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。
//
// 示例 1:
// 输入: [1,2,3,4,5]
// 输出: true
//
// 示例 2:
// 输入: [5,4,3,2,1]
// 输出: false


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    // 暴力 dp
    bool increasingTriplet(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> dp(len,1);
        if(len < 3)
        {
            return 0;
        }
        
        int ans = 1;

        for(int i = 1; i < len; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] =  max(dp[i],dp[j]+1);
                    ans = max(ans,dp[i]);
                }
                if(ans >= 3)
                {
                    return true;
                }
            }
        }
        return false;
    }
};