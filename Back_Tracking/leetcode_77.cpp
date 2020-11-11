//          77. 组合
//
// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//
// 示例:
// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    vector<int> check;
    void dfs(int start,int n,int k)
    {
        if(t.size() == k)
        {
            ans.push_back(t);
            return;
        }
        
        for(int i = start; i <= n; ++i)
        {
            if(check[i] == false)
            {
                check[i] = true;
                t.push_back(i);
                dfs(i+1,n,k);
                t.pop_back();
                check[i] = false;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        check.resize(n+1);
        dfs(1,n,k);
        return ans;
    }
};