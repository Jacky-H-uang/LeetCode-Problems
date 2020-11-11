//          47. 全排列 II
//
// 给定一个可包含重复数字的序列，返回所有不重复的全排列。
//
// 示例:
// 输入: [1,1,2]
// 输出:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]


#include<bits/stdc++.h>
using namespace std;

// Medium


// 怎么进行数组判重: 直接利用hashset来去重就行
class Solution {
public:
    set<vector<int>> ans;
    vector<int> temp;
    vector<bool> check;
    int len;

    void dfs(vector<int>& nums)
    {
        if(temp.size() == len)
        {
            ans.insert(temp);
            return;
        }

        for(int i = 0; i < len; ++i)
        {
            if(check[i] == false)
            {
                temp.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                temp.pop_back();
                check[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        this->len = nums.size();
        check.resize(len,false);
        dfs(nums);
        
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};