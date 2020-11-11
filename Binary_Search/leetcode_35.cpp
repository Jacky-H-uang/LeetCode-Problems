// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 你可以假设数组中无重复元素。
//
// 示例 1:
//
// 输入: [1,3,5,6], 5
// 输出: 2
//
// 示例 2:
// 输入: [1,3,5,6], 2
// 输出: 1
//
// 示例 3:
// 输入: [1,3,5,6], 7
// 输出: 4
//
// 示例 4:
// 输入: [1,3,5,6], 0
// 输出: 0

#include<iostream>
#include<vector>
using namespace std;

//Easy

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int len = nums.size();
        int lo = 0;
        int hi = len-1;
        int mid;
        if(len == 0)
        {
            return 0;
        }
        while (lo<=hi)
        {
            mid = (hi+lo)/2;
            if(target<nums[mid])
            {
                hi = mid-1;
            }
            else if(target>nums[mid])
            {
                lo = mid+1;
            }
            else
            {
                return mid;
            }
        }
        if(nums[mid]<target)
        {
            return mid+1;
        }
        if(nums[mid]>target)
        {
            return mid;
        }
        return -1;
    }
};


int main()
{
    vector<int> n = {1,50,51,60,999,1000};
    Solution s;
    int r = s.searchInsert(n,55);
    cout<<r<<endl;
    system("pause");
    return 0;
}