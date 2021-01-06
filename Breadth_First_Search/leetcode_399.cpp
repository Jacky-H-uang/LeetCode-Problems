//                                           399. 除法求值
//
// 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，
// 其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
// 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
// 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
// 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
//
//
// 示例 1：
// 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
// 解释：
// 条件：a / b = 2.0, b / c = 3.0
// 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
//
// 示例 2：
// 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// 输出：[3.75000,0.40000,5.00000,0.20000]
//
// 示例 3：
// 输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// 输出：[0.50000,2.00000,-1.00000,-1.00000]
//
//
// 提示：
// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj 由小写英文字母与数字组成



#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
private:
    unordered_map<string,int> st;
    map<pair<int,int>,double> memo;
    int cur = 0;
public:
    double bfs(int x, int y,vector<bool>& checked) {
        if(x == y)  return 1.0;
        queue<int> q;
        map<pair<int,int>,double> Z;
        Z[make_pair(x,x)] = 1.0;
        q.push(x);
        while(!q.empty()) {
            int temp = q.front();
            checked[temp] = true;
            q.pop();
            for(int i = 0; i < cur; ++i) {
                if(checked[i] == true)  continue;
                if(i == temp)   continue;
                if(memo.count(make_pair(temp,i)) == 1) {
                    Z[make_pair(x,i)] = Z[make_pair(x,temp)] * memo[make_pair(temp,i)];
                    if(memo.count(make_pair(i,y)) == 1) {
                        return Z[make_pair(x,i)] * memo[make_pair(i,y)];
                    }
                    q.push(i);
                }
            }
        }
        // 0 1     2 3
        // 0 2  1 3  1 0  3 2
        return -1.0;
    }

    // 可以写一个 UF 但是我不会 , 所以想到用普通的 DFS
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 先哈希映射 , 其实可以采用 26 个字母来映射但是由于存在多字母那么则需要其他映射规则
        vector<double> ans;
        int n = equations.size();
        for(int i = 0; i < n; ++i) {
            if(st.count(equations[i][0]) != 1) {
                st[equations[i][0]] = cur++;
            }
            if(st.count(equations[i][1]) != 1) {
                st[equations[i][1]] = cur++;
            }
        }

        // 记录一个 memo
        for(int i = 0; i < n; ++i) {
            memo[make_pair(st[equations[i][0]],st[equations[i][0]])] = 1.0;
            memo[make_pair(st[equations[i][1]],st[equations[i][1]])] = 1.0;
            memo[make_pair(st[equations[i][0]] , st[equations[i][1]])] = values[i];
            memo[make_pair(st[equations[i][1]] , st[equations[i][0]])] = 1.0 / values[i];
        }

        // 然后开始 dfs
        for(auto& q : queries) {
            double aux = -1.0;
            // 先判断在不在 st 表里面
            if(st.count(q[0]) == 1 && st.count(q[1]) == 1) {
                // 其实在这里就可以采用 uf 再进行 O1 的查询 也可以用简单的dfs
                int x = st[q[0]];
                int y = st[q[1]];
                vector<bool> checked(cur);
                checked.clear();
                aux = bfs(x,y,checked);
            }
            ans.push_back(aux);
        }

        return ans;
    }
};