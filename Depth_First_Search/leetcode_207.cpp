// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
//  
// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
//
//
// Example 2:
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
//  
//
//
// Constraints:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
// 1 <= numCourses <= 10^5



#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    // 记录三种状态 ： 1. 未搜索    2. 搜索中   3. 已搜索
    // 深度搜索至那些最后学的课程
    
    vector<vector<int>> edges;          // 记录出度课程关系
    vector<int> visited;                // 记录状态数组   0 ： 未搜索       1 ：搜索中      2 ： 已搜索
    bool valid = true;
    

    void initDegree(vector<vector<int>>& ed , vector<vector<int>>& pre)
    {
        for(int i = 0; i < pre.size(); ++i)
        {
            int a = pre[i][0];              // 后修课程
            int b = pre[i][1];              // 先修课程
            ed[b].push_back(a);             // 记录课程的出度关系
        }
    }

    // dfs + 回溯课程 并将其学过的标记为 2
    void dfs(int u)
    {
        visited[u] = 1;
        for(int e : edges[u])
        {
            if(visited[e] == 0)
            {
                dfs(e);
                if(!valid)
                {
                    return;
                }
            }
            else if(visited[e] == 1)
            {
                // 遇到环的时候就返回 false
                valid = false;
                return;
            }
        }

        // 最后将其加入到 stack 中并标记状态为 2 为已搜索的课程
        visited[u] = 2;
    }
    

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        edges = vector<vector<int>>(numCourses);
        visited = vector<int>(numCourses);

        // 初始化 edges
        initDegree(edges,prerequisites);

        for(int i = 0; i < numCourses && valid; ++i)            // 只要 valid 为 false 则图中必有回路（即必形成环） 
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }

        return valid;
    }
};