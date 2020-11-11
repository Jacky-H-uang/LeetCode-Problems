//          Course Schedule II

// There are a total of n courses you have to take, labeled from 0 to n-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
//
// Example 1:
// Input: 2, [[1,0]] 
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
//              course 0. So the correct course order is [0,1] .
//
// Example 2:
// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
//
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Medium


//对于图 G 中的任意一条有向边 (u, v)，u 在排列中都出现在 v 的前面
//那么称该排列是图 G 的「拓扑排序」。
//只有有向无环图才存在拓扑排序.
class Solution {
private:
    vector<vector<int>> edges;              // 存储有向图
    vector<int> visited;                    // 标记每个节点的状态：0 = 未搜索，1 = 搜索中，2 = 已完成
    vector<int> result;                     // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
    bool invalid;                           // 判断有向图中是否有环
public:
    void dfs(int u)
    {
        visited[u] = 1;                     // 将节点标记为「搜索中」
        for(int v:edges[u])                 // 搜索其相邻节点   只要发现有环，立刻停止搜索
        {
            if(visited[v] == 0)             // 如果「未搜索」那么搜索相邻节点
            {
                dfs(v);
                if(invalid)
                {
                    return;
                }
            }
            else if (visited[v] == 1)       // 如果「搜索中」说明找到了环
            {
                invalid = true;
                return;
            }
        }
        visited[u] = 2;                     // 将节点标记为「已完成」
        result.push_back(u);                // 将节点入栈
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) 
        {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && !invalid; ++i)        // 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
        {
            if (!visited[i]) 
            {
                dfs(i);
            }
        }
        if (invalid) 
        {
            return {};
        }
        reverse(result.begin(), result.end());      // 如果没有环，那么就有拓扑排序
                                                    // 注意下标 0 为栈底，因此需要将数组反序输出
        return result;
    }
};