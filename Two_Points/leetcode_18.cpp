// 4 SUM

// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
// Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
// The solution set must not contain duplicate quadruplets.
//
// Example:
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Medium

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        int len = nums.size();
        for(int i=0;i<len-3;i++)
        {
            for(int j=i+1;j<len-2;j++)
            {
                int l = j+1;
                int r = len-1;
                while(l<r)
                {
                    if(nums[i]+nums[j]+nums[l]+nums[r]-target<0)
                    {
                        l++;
                    }
                    else if(nums[i]+nums[j]+nums[l]+nums[r]-target>0)
                    {
                        r--;
                    }
                    else
                    {
                        v.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        return v;
    }
};


int main()
{
    vector<int> v ={-3,-2,-1,0,0,1,2,3};
    Solution s;
    vector<vector<int>> r = s.fourSum(v,0);
    for(auto& t:r)
    {
        for(auto&i:t)
        {
            cout<<i<<"  ";
        }
        cout<<"\n";
    }
    system("pause");
    return 0;
}