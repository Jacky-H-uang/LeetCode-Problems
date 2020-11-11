//                      s18. 四数之和
//
// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
// 找出所有满足条件且不重复的四元组。
//
// 注意：
// 答案中不可以包含重复的四元组。
//
// 示例：
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        // 双指针来找到两个数
        for(int i = 0; i < n-3; ++i)
        {
            for(int j = i+1; j < n-2; ++j)
            {
                int L = j + 1;
                int R = n-1;
                while(L < R)
                {
                    if(nums[i] + nums[j] + nums[L] + nums[R] < target)              L++;
                    else if(nums[i] + nums[j] + nums[L] + nums[R] > target)         R--;
                    else                                                            
                    {
                        ans.insert({nums[i],nums[j],nums[L],nums[R]});
                        L++;
                        R--;
                    }
                }
            }
        }
        
        return vector<vector<int>>(ans.begin(),ans.end());;
    }
};