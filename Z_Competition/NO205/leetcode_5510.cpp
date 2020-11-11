//              5510. 保证图可完全遍历
//
// Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：
// 类型 1：只能由 Alice 遍历。
// 类型 2：只能由 Bob 遍历。
// 类型 3：Alice 和 Bob 都可以遍历。
// 给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。
// 请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。
// 如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。
// 返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。
//
//
// 示例 1：
// 输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// 输出：2
// 解释：如果删除 [1,1,2] 和 [1,1,3] 这两条边，Alice 和 Bob 仍然可以完全遍历这个图。再删除任何其他的边都无法保证图可以完全遍历。所以可以删除的最大边数是 2 。
//
//
// 示例 2：
// 输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// 输出：0
// 解释：注意，删除任何一条边都会使 Alice 和 Bob 无法完全遍历这个图。
//
//
// 示例 3：
// 输入：n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// 输出：-1
// 解释：在当前图中，Alice 无法从其他节点到达节点 4 。类似地，Bob 也不能达到节点 1 。因此，图无法完全遍历。
//
//
// 提示：
// 1 <= n <= 10^5
// 1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
// edges[i].length == 3
// 1 <= edges[i][0] <= 3
// 1 <= edges[i][1] < edges[i][2] <= n
// 所有元组 (typei, ui, vi) 互不相同



#include<bits/stdc++.h>
using namespace std;

// Hard


class Solution {
private:
    vector<int> pa,pb;
public:
    // Union-Find 查找函数
    int find(vector<int>&p , int x)
    {
        if(p[x] != x)
        {
            p[x] = find(p,p[x]);
        }

        return p[x];
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        pa.resize(n+1);
        pb.resize(n+1);    
        for(int i = 1; i <= n; ++i)
        {
            pa[i] = pb[i] = i;
        }

        int ans = 0;
        int ca = n;
        int cb = n;

        // 遍历 Type3 的边
        for(auto& e : edges)
        {
            if(e[0] == 3)
            {
                int x = e[1];
                int y = e[2];
                int pax = find(pa,x) , pay = find(pa,y);
                int pbx = find(pb,x) , pby = find(pb,y);

                if(pax != pay)
                {
                    pa[pax] = pay;
                    ca--;
                    pb[pbx] = pby;
                    cb--;
                }
                else                // （克鲁斯卡尔算法）两个不同集合的边添加进来
                {
                    ans++;
                }
            }
        }

        // 遍历 Type1 的边 (Alice) 和 Type2 的边 (Bob)
        for(auto& e : edges)
        {
            int t = e[0];
            int x = e[1];
            int y = e[2];
            if(t == 3)
            {
                continue;
            }

            // 处理 Alice
            if(t == 1)
            {
                int pax = find(pa,x);
                int pay = find(pa,y);
                if(pax != pay)
                {
                    pa[pax] = pay;
                    ca--;
                }
                else
                {
                    ans++;
                }
            }

            // 处理 Bob
            if(t == 2)
            {
                int pbx = find(pb,x);
                int pby = find(pb,y);
                if(pbx != pby)
                {
                    pb[pbx] = pby;
                    cb--;
                }
                else
                {
                    ans++;
                }
            }
        }

        if(ca > 1 || cb > 1)
        {
            return -1;
        }

        return ans;
    }
};