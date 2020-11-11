//                          1365. How Many Numbers Are Smaller Than the Current Number
//
// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
// That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
// Return the answer in an array.
//
//
// Example 1:
// Input: nums = [8,1,2,2,3]
// Output: [4,0,1,1,3]
// Explanation: 
// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
// For nums[1]=1 does not exist any smaller number than it.
// For nums[2]=2 there exist one smaller number than it (1). 
// For nums[3]=2 there exist one smaller number than it (1). 
// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
//
//
// Example 2:
// Input: nums = [6,5,4,8]
// Output: [2,1,0,3]
//
//
// Example 3:
// Input: nums = [7,7,7,7]
// Output: [0,0,0,0]
//
//
// Constraints:
// 2 <= nums.length <= 500
// 0 <= nums[i] <= 100


#include<bits/stdc++.h>
using namespace std;


// 桶排序的思想，用一个累加器来记录
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans;
        vector<int> aux(101);

        for(auto& i : nums)     aux[i]++;

        int cnt = 0;
        for(int i = 0; i < 101; ++i)
        {
            int tmp = aux[i];
            aux[i] = cnt;
            cnt += tmp;
        }

        for(auto& i : nums)     ans.push_back(aux[i]);

        return ans;
    }
};