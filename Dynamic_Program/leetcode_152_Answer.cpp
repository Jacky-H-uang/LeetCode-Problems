/*                                                              Maximum Product Subarray                                                            */

// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// Example 1:
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
// Example 2:
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Medium


class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> maxN(nums);
        vector<int> minN(nums);
        for(int i=1;i<len;i++)
        {
            maxN[i] = max(maxN[i-1]*nums[i],max(minN[i-1]*nums[i],nums[i]));
            minN[i] = min(maxN[i-1]*nums[i],min(minN[i-1]*nums[i],nums[i]));
        }
        return *max_element(maxN.begin(),maxN.end());
    }
};

int main()
{
    vector<int> v = {2,3,-2,4};
    Solution s;
    int r = s.maxProduct(v);
    cout<<r<<endl;
    system("pause");
    return 0;
}