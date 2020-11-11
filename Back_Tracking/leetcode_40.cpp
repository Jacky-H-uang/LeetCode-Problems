//          40. 组合总和 II
//
// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用一次。
//
// 说明：
// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。 
//
// 示例 1:
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
// 示例 2:
// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:
// [
//   [1,2,2],
//   [5]
// ]

#include<bits/stdc++.h>
using namespace std;

// Medium


// 需要去重 --（去除答案中的重复）
class Solution {
private:
    set<vector<int>> ans;               // 直接声明为 set 去重
    vector<int> seq;
    int len;

public:
    void dfs(vector<int>& candidates, int start,int target) 
    {
        if(target == 0)
        {
            ans.insert(seq);
            return;
        }

        for(int i = start; i < len && candidates[i] <= target; ++i)
        {
            seq.push_back(candidates[i]);
            dfs(candidates,i+1,target-candidates[i]);
            seq.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        
        sort(candidates.begin(), candidates.end());
        this->len = candidates.size();
        dfs(candidates,0,target);
        
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};