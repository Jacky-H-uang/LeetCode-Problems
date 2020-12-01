#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() <= 0)    return {-1,-1};
        
        int a = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int b = upper_bound(nums.begin(),nums.end(),target) - nums.begin();

        if(a >= nums.size())                                return {-1,-1};
        if(nums[a] == target && nums[b-1] == target)        return {a,b-1};                   
        return {-1,-1};
    }
};