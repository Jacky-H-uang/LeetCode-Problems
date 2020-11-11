// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 请你找出所有满足条件且不重复的三元组。
//
// 注意：答案中不可以包含重复的三元组。  
//
// 示例：
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Medium

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int len = nums.size();
        int target;
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i=0;i<len;i++)
        {
            int l = i+1;
            int r = len-1;
            target = nums[i];
            if(i>0 && nums[i] == nums[i-1])         // 防止头元素的重复元素
            {
                continue;
            }
            while (l<r)
            {
                if(nums[l] + nums[r] + target <0)
                {
                    ++l;
                }
                else if (nums[l] + nums[r] + target >0)
                {
                    --r;
                }
                else
                {
                    v.push_back({target,nums[l],nums[r]});
                    ++l;
                    --r;
                    while (l<r && nums[l] == nums[l-1])
                    {
                        ++l;
                    }
                    while (l<r && nums[r] == nums[r+1])
                    {
                        --r;
                    }
                }
            }
        }
        return v;
    }
};



int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> r = s.threeSum(a);
    for(int i=0;i<r.size();i++)
    {
        for(auto& k:r[i])
        {
            cout<<k<<" ";
        }
        cout<<"\n";
    }
    system("pause");
    return 0;
}