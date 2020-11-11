//      5513. 连接所有点的最小费用
//
// 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。
// 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。
// 请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。
//
//
// 示例 1：
// 输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// 输出：20
// 解释：
// 我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
// 注意到任意两个点之间只有唯一一条路径互相到达。
//
// 示例 2：
// 输入：points = [[3,12],[-2,5],[-4,1]]
// 输出：18
//
// 示例 3：
// 输入：points = [[0,0],[1,1],[1,0],[-1,1]]
// 输出：4
//
// 示例 4：
// 输入：points = [[-1000000,-1000000],[1000000,1000000]]
// 输出：4000000
//
// 示例 5：
// 输入：points = [[0,0]]
// 输出：0
//
//
// 提示：
// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// 所有点 (xi, yi) 两两不同。

#include<bits/stdc++.h>
using namespace std;
#define Inf 0x7fffffff

// Medium

// 问题可以转化为 Prim 算法中的最小生成树
class Solution {
public:
    vector<vector<int>> Vex;

    int minCost(int n)
    {
        vector<int> check(n);
        int s = 0;
        int ans = 0;
        vector<int> cost = Vex[s];
        
        for(int i = 0; i < n; ++i)
        {
            int minC = Inf;
            int u = -1;

            // 贪心的找到与此时所连接点集合距离最小的点 u
            for(int j = 0; j < n; ++j)
            {
                if(!check[j] && cost[j]< minC)
                {
                    minC = cost[u=j];
                }
            }

            ans += minC;
            check[u] = true;

            for(int j = 0; j < n; ++j)
            {
                // 更新每个点的最短距离
                if(!check[j] && cost[j] > Vex[j][u])
                {
                    cost[j] = Vex[j][u];
                }
            }
        }

        return ans;
    }

    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        Vex.resize(n,vector<int>(n));
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                int difx = abs(points[j][0] - points[i][0]);
                int dify = abs(points[j][1] - points[i][1]);
                int ManHaDun = difx + dify;

                Vex[i][j] = ManHaDun;
                Vex[j][i] = ManHaDun;
            }
        }

        return minCost(n);
    }
};