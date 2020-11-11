// 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
//  
// 示例 1:
// 输入: [1,2,0]
// 输出: 3
//
// 示例 2:
// 输入: [3,4,-1,1]
// 输出: 2
//
// 示例 3:
// 输入: [7,8,9,11,12]
// 输出: 1
//  
// 提示：
// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。


#include<iostream>
#include<vector>
using namespace std;

// Hard

class Solution {
public:
    // 建立一个 hashset 但是空间复杂度为 O（n）
    // 题目要求空间复杂度为 O（1） 所以要在数组原地 Hash
    // Key :    nums[i] - 1
    // Value:   nums[i]
    int firstMissingPositive(vector<int>& nums) 
    {
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            while(nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i])
            {
                // 交换位置形成哈希表
                int temp = nums[i]-1;
                nums[i] = nums[temp];
                nums[temp] = temp+1;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }
        return len+1;
    }
};