// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
//
// Note:
// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may not use the same element twice.
//
//
// Example:
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int ans1 = 0;
        int ans2 = 0;
        if(numbers.size() <= 1)
        {
            return {0,0};
        }
        for(int i=0;i<numbers.size();i++)
        {
            int l = i+1;
            int r = numbers.size()-1;
            while(l <= r)
            {
                int mid = l + (r-l)/2;
                if(numbers[mid] > target-numbers[i])
                {
                    r = mid-1;
                }
                else if(numbers[mid] < target-numbers[i])
                {
                    l = mid+1;
                }
                else
                {
                    ans1 = i+1;
                    ans2 = mid+1;
                    return {ans1,ans2};
                }
            }
        }
        return {0,0};
    }
};