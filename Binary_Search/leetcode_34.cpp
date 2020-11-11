// 34. 在排序数组中查找元素的第一个和最后一个位置
//
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 你的算法时间复杂度必须是 O(log n) 级别。
// 如果数组中不存在目标值，返回 [-1, -1]。
//
// 示例 1:
// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]
//
// 示例 2:
// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return {-1,-1};
        }
        
        int a = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int b = upper_bound(nums.begin(),nums.end(),target)-nums.begin();


        if(a >= nums.size())
        {
            return {-1,-1};
        }

        if(nums[a] == target && nums[b-1] == target)
        {
            return {a,b-1};
        }

        return {-1,-1};
    }
};