// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
// 示例:
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

#include<iostream>
#include<vector>
using namespace std;
//Easy

class Solution1                     //DP(Kadane 算法)        在整个数组或在固定大小的滑动窗口中找到总和或最大值或最小值的问题可以通过动态规划（DP）在线性时间内解决。    
{

    public:
        int maxNums(vector<int>& n)
        {
            int r = INT32_MIN;
            for(auto& i: n)
            {
                if(i>r)
                {
                    r = i;
                }
            }
            return r;
        }
        int maxSubArray(vector<int>& nums) 
        {
            int len = nums.size();
            for(int i=1;i<len;i++)
            {
                nums[i] = nums[i] + max(nums[i-1],0);
            }
            return maxNums(nums);
        }
};

class Solution2                     //分治法
{
    public:
        int maxSubArray(vector<int>& nums)
        {
            
        }
};


int main()
{
    Solution1 s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    int r = s.maxSubArray(v);
    cout<<r<<endl;
    system("pause");
    return 0;
}