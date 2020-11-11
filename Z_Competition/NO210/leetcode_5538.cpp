//                                  5538. 统计子树中城市之间最大距离
//
// 给你 n 个城市，编号为从 1 到 n 。同时给你一个大小为 n-1 的数组 edges ，
// 其中 edges[i] = [ui, vi] 表示城市 ui 和 vi 之间有一条双向边。
// 题目保证任意城市之间只有唯一的一条路径。换句话说，所有城市形成了一棵 树 。
// 一棵 子树 是城市的一个子集，且子集中任意城市之间可以通过子集中的其他城市和边到达。
// 两个子树被认为不一样的条件是至少有一个城市在其中一棵子树中存在，但在另一棵子树中不存在。
// 对于 d 从 1 到 n-1 ，请你找到城市间 最大距离 恰好为 d 的所有子树数目。
// 请你返回一个大小为 n-1 的数组，其中第 d 个元素（下标从 1 开始）是城市间 最大距离 恰好等于 d 的子树数目。
// 请注意，两个城市间距离定义为它们之间需要经过的边的数目。
//
//
// 示例 1：
// 输入：n = 4, edges = [[1,2],[2,3],[2,4]]
// 输出：[3,4,0]
// 解释：
// 子树 {1,2}, {2,3} 和 {2,4} 最大距离都是 1 。
// 子树 {1,2,3}, {1,2,4}, {2,3,4} 和 {1,2,3,4} 最大距离都为 2 。
// 不存在城市间最大距离为 3 的子树。
//
// 示例 2：
// 输入：n = 2, edges = [[1,2]]
// 输出：[1]
//
// 示例 3：
// 输入：n = 3, edges = [[1,2],[2,3]]
// 输出：[2,1]
//
//
// 提示：
// 2 <= n <= 15
// edges.length == n-1
// edges[i].length == 2
// 1 <= ui, vi <= n
// 题目保证 (ui, vi) 所表示的边互不相同。


#include<bits/stdc++.h>
using namespace std;

// Hard

const int MAXN = 20;
queue<int> que;
int dist[MAXN];
vector<int> edge[MAXN];


void bfs(int x, int n, int s)
{
    while(!que.empty()) que.pop();
    memset(dist, -1, sizeof(dist));
    que.push(x); 
    dist[x] = 0;
    while(!que.empty())
    {
        int now = que.front(); que.pop();
        for (int v: edge[now])
        {
            if (((s >> v) & 1) == 0) continue;
            if (dist[v] == -1)
            {
                dist[v] = dist[now] + 1;
                que.push(v);
            }
        }
    }
}

class Solution {
public:
    vector<int> ans;
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) 
    {
        ans.clear(); for (int i = 1; i <= n - 1; i++) ans.push_back(0);
        
        for (int i = 0; i < n; i++) edge[i].clear();
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            int a = edges[i][0] - 1, b = edges[i][1] - 1;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        
        int lim = (1<<n);
        for (int s = 1; s < lim; s++)
        {
            int total = 0, root = -1;
            for (int i = 0; i < n; i++)
            {
                if ((s >> i) & 1) 
                {
                    if (root == -1) root = i;
                    ++total;
                }
            }
            if (total <= 1) continue;
            
            int mx = root, cnt = 0;

            bfs(root, n, s);
            
            for (int i = 0; i < n; i++)
            {
                if (dist[i] >= 0)
                {
                    ++cnt;
                    if (dist[i] > dist[mx]) mx = i;
                }
            }
            if (cnt != total) continue;
            
            bfs(mx, n, s);
            
            for (int i = 0; i < n; i++)
            {
                if (dist[i] >= 0 && dist[i] > dist[mx]) mx = i;
            }
            
            ans[dist[mx] - 1] += 1;
        }
        
        return ans;
    }
};