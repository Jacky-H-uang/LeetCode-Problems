//      560. Subarray Sum Equals K

// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
//
// Constraints:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//Medium

//前缀和 + 哈希表优化
// pre[i]=pre[i−1]+nums[i]          pre[i] --> 前 i 项和
// pre[i]−pre[j−1] == k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) 
        {
            pre += x;
            if (mp.find(pre - k) != mp.end()) 
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};


int main()
{
    vector<int> v = {1,2,1,2,1};
    Solution s;
    int r = s.subarraySum(v,3);
    cout<<r<<endl;
    system("pause");
    return 0;
}