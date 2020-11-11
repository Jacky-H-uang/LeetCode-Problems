//                  78. 子集
//
// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
// 说明：解集不能包含重复的子集。
//
// 示例:
// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;

        // 简单的回溯就行
        function<void(int)> dfs = [&](int start) {
            ans.push_back(tmp);

            for(int i = start; i < n; ++i)
            {
                tmp.push_back(nums[i]);
                dfs(i+1);
                tmp.pop_back();
            }
        };

        dfs(0);

        return ans;
    }
};