//                      349. Intersection of Two Arrays
//
// Given two arrays, write a function to compute their intersection.
//
// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
//
// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
//
// Note:
// Each element in the result must be unique.
// The result can be in any order.


#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    // 简单的哈希集合存元素和 set 去重
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> cnt;
        set<int> ans;
        for(int i = 0; i < nums1.size(); ++i)       cnt.insert(nums1[i]);


        for(auto& x : nums2)
        {
            if(cnt.count(x) == 1)   ans.insert(x);
        }

        return vector<int>(ans.begin() ,ans.end());
    }
};