//              491. 递增子序列
//
// 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
//
//
// 示例:
// 输入: [4, 6, 7, 7]
// 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
//
//
// 说明:
// 给定数组的长度不会超过15。
// 数组中的整数范围是 [-100,100]。
// 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        int n = nums.size();

        vector<vector<int>> ans;            // 返回数组
        vector<int> v;                      // 统计当前遍历的时候递增的数组
        set<vector<int>> hashset;           // 哈希集合不需要手动去重

        // 类似于全排序的类型，不过有限制就是必须递增
        function<void(int)> dfs =  [&](int start) {
            if(v.size() >= 2)
            {
                hashset.insert(v);
            }

            for(int i = start; i < n; ++i)
            {
                // 当前数组为空 并且 数组的最大元素大于当前数字的时候继续循环
                if(!v.empty() && v.back() > nums[i])
                {
                    continue;
                }

                v.push_back(nums[i]);
                dfs(i+1);
                v.pop_back();
            }
        }; 

        dfs(0);
        ans = vector<vector<int>>(hashset.begin(),hashset.end());
        
        return ans;
    }
};