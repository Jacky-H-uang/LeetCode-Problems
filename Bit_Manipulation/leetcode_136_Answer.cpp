//  Single Number

// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
// Input: [2,2,1]
// Output: 1
//
// Example 2:
// Input: [4,1,2,1,2]
// Output: 4

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int result = 0;
        for(auto& i:nums)
        {
            result ^= i;
        }
        return result;
    }
};


int main()
{
    vector<int> v = {2,2,1};
    Solution s;
    cout<<s.singleNumber(v)<<endl;
    system("pause");
    return 0;
}