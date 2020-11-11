//                      560. Subarray Sum Equals K
//
// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
//
//
// Constraints:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ht;
        ht[0] = 1;
        int prefix = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            
            if(ht.find(prefix - k) != ht.end())   ans += ht[prefix - k];
            
            ht[prefix]++;
        }
        
        return ans;
    }
};