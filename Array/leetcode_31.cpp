// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
// 必须原地修改，只允许使用额外常数空间。
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Medium

class Solution {
public:
    void change(vector<int>& nums,int i,int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void nextPermutation(vector<int>& nums) 
    {
        int len = nums.size();
        if(len <= 1)
        {
            return;
        }
        int val = nums[len-1];
        int ptr = len-1;
        for(int i=len-1;i>=0;i--)
        {
            if(nums[i] > val)
            {
                val = nums[i];
            }
            else if(nums[i] == val);
            else
            {
                ptr = i;
                break;
            }
        }
        if(ptr == len-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        sort(nums.begin()+ptr+1,nums.end());
        auto exchange_ptr = upper_bound(nums.begin()+ptr+1,nums.end(),nums[ptr])-nums.begin();
        change(nums,ptr,exchange_ptr);
    }
};