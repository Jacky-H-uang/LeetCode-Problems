//                                          1590. Make Sum Divisible by P
//
// Given an array of positive integers nums, 
// remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. 
// It is not allowed to remove the whole array.
// Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
// A subarray is defined as a contiguous block of elements in the array.
//
//
// Example 1:
// Input: nums = [3,1,4,2], p = 6
// Output: 1
// Explanation: The sum of the elements in nums is 10, which is not divisible by 6. 
//              We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
//
// Example 2:
// Input: nums = [6,3,5,2], p = 9
// Output: 2
// Explanation: We cannot remove a single element to get a sum divisible by 9. 
//              The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
//
// Example 3:
// Input: nums = [1,2,3], p = 3
// Output: 0
// Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
//
// Example 4:
// Input: nums = [1,2,3], p = 7
// Output: -1
// Explanation: There is no way to remove a subarray in order to get a sum divisible by 7.
//
// Example 5:
// Input: nums = [1000000000,1000000000,1000000000], p = 3
// Output: 0
//
//
// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= p <= 109


#include<bits/stdc++.h>
using namespace std;

// Medium

/*
    sum % p != 0
    
    sum % p  = ((sum - subsum)%p + subsum % p) % p
    
    But (sum - subsum)%p == 0 Should be True
    
    So , sum % p = subsum % p
    
    So Find the Smallest Subarray Whose Remainder is (sum % p);
    
    How to do this in O(N)?
    Try this problem: Subarray Sums Divisible by K

*/
#define LL long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // 先算 sum % p 是否等于 0 
        LL sum = accumulate(nums.begin(),nums.end(),0LL);
        int mod = sum % p;
        if(mod == 0)        return 0;

        // the , Find the Smallest Subarray Whose Remainder is (sum % p);
        sum = 0;
        unordered_map<int,int> ht;
        ht[mod] = -1;
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum = (sum + nums[i]) % p;
            
            if(ht.find(sum) != ht.end())
            {
                res = min(res , i - ht[sum]);
            }
            int idx = (sum + mod) % p;
            ht[idx] = i;
        }

        return res == INT_MAX || res == nums.size() ? -1 : res;
    }
};



// 3  1  4  2
// sum = 10     mod = 4;

// i = 0
// s = 3 % 6 = 3
// tar = 1
// m[3] = 0

// i = 1
// s = 4 % 6 = 2
// tar = 2
// m[2] = 1

// i = 2
// s =  8 % 6 = 2
// tar = 2
// res = min(INT_MAX , i - m[2]) = 1

// ... 

// p = 6