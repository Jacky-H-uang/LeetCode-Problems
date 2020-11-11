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
using namespace std;

// Hard

// 递归回溯 会超时 不过也要求掌握
class Solution {
private:
    void helper(vector<int>& nums,int coins,int& ans)
    {
        // boundary
        if(nums.size() == 0)
        {
            ans = max(ans,coins);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            int temp = nums[i];
            int delta = nums[i]*(i-1<0?1:nums[i-1])*(i+1>nums.size()-1?1:nums[i+1]);
            nums.erase(nums.begin()+i);
            helper(nums,coins+delta,ans);
            nums.insert(nums.begin()+i,temp);
        }
    }
public:
    int maxCoins(vector<int>& nums) 
    {
        int ans = 0;
        helper(nums,0,ans);
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> v = {3,1,5,8};
    cout<<s.maxCoins(v)<<endl;
    system("pause");
    return 0;
}