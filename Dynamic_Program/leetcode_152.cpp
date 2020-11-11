//          Maximum Product Subarray

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
using namespace std;

// Medium

// 暴力法
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int len = nums.size();
        int max = nums[0];
        for(int i=0;i<len;i++)
        {
            int temp =nums[i];
            if(temp > max)
            {
                max = temp;
            }
            for(int j=i+1;j<len;j++)
            {
                temp *= nums[j];
                if(temp > max)
                {
                    max = temp;
                }
            }
        }
        return max;
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