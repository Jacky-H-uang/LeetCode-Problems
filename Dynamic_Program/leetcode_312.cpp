// 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
// 现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得 nums[left] * nums[i] * nums[right] 个硬币。 
// 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
// 求所能获得硬币的最大数量。
//
// 说明:
// 你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
// 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//
//
// 示例:
// 输入: [3,1,5,8]
// 输出: 167 
// 解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//      coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


#include<bits/stdc++.h>
#include<math.h>
using namespace std;

// Hard

// 记忆化递归
class Solution {
private:
    vector<vector<int>> dp;
    int helper(vector<int>& nums,int i,int j)
    {
        // boundary
        if(i > j)
        {
            return 0;
        }
        if(dp[i][j] > 0)
        {
            return dp[i][j];
        }
        for(int k=i;k<=j;k++)
        {
            int left = helper(nums,i,k-1);
            int right = helper(nums,k+1,j);
            int delta = nums[i-1]*nums[k]*nums[j+1];
            dp[i][j] = max(dp[i][j],left+right+delta);
        }
        return dp[i][j];
    }
public:
    int maxCoins(vector<int>& nums) 
    {
        int len = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp = vector<vector<int>>(len+2,vector<int>(len+2));
        int ans = helper(nums,1,len);
        return ans;
    }
};