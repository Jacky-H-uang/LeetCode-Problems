//                      416. 分割等和子集
//
// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// 注意:
// 每个数组中的元素不会超过 100
// 数组的大小不会超过 200
//
// 示例 1:
// 输入: [1, 5, 11, 5]
// 输出: true
// 解释: 数组可以分割成 [1, 5, 5] 和 [11].
//
// 示例 2:
// 输入: [1, 2, 3, 5]
// 输出: false
// 解释: 数组不能分割成两个元素和相等的子集.

#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    // 转换为 0 - 1 背包问题
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) 
        {
            return false;
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        int target = sum / 2;

        if (sum & 1)            return false;
        if (maxNum > target)    return false;

        // dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j。
        // 初始时，dp 中的全部元素都是 false。
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        for (int i = 0; i < n; i++)         dp[i][0] = true;

        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) 
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)       dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                else                dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n - 1][target];
    }
};