// 给定一个无序的整数数组，找到其中最长上升子序列的长度。
//
// 示例:
// 输入: [10,9,2,5,3,7,101,18]
// 输出: 4 
// 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
//
//
// 说明:
// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
// 你算法的时间复杂度应该为 O(n2) 。
// 进阶: 你能将算法的时间复杂度降低到 O(nlogn) 吗?


#include<bits/stdc++.h>
using namespace std;

// DP 基础题

class Solution1{
public:
    // 暴力dp
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if(len <= 0)
        {
            return 0;
        }
        int ans = 1;
        vector<int> dp(len,1);
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};




class Solution2{
public:
    // 基于 BinarySearch 的 DP 时间复杂度 为O(nlogn)
    // 观察可发现 搜索的过程中只与搜索的边界有关,搜索体内部元素可以替换，搜索的边界不变即可
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if(len <= 0)
        {
            return 0;
        }
        vector<int> dp(len);
        dp[0] = nums[0];
        int ans = 0;
        for(int i=1;i<len;i++)
        {
            if(dp[ans] < nums[i])
            {
                dp[++ans] = nums[i];
            }
            else
            {
                int k = lower_bound(dp.begin(),dp.begin()+ans+1,nums[i])-dp.begin();
                dp[k] = nums[i];
            }
        }
        return ans+1;
    }
};