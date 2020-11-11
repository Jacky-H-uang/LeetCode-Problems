// 魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。
// 给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。
//
// 示例1:
//  输入：nums = [0, 2, 3, 4, 5]
//  输出：0
//  说明: 0下标的元素为0
//
// 示例2:
//  输入：nums = [1, 1, 1]
//  输出：1
//
// 提示:
// nums长度在[1, 1000000]之间




#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    // 分治 + 剪枝
    int getAnswer(vector<int>& nums, int left, int right) 
    {
        if (left > right)
        {
            return -1;
        }

        int mid = (right - left) / 2 + left;

        int leftAnswer = getAnswer(nums, left, mid - 1);

        if (leftAnswer != -1)
        {
            return leftAnswer;
        }
        else if (nums[mid] == mid) 
        {
            return mid;
        }

        return getAnswer(nums, mid + 1, right);
    }


    int findMagicIndex(vector<int>& nums) 
    {
        return getAnswer(nums, 0, (int) nums.size() - 1);
    }
};
