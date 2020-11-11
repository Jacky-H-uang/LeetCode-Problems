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
#include<queue>
#include<algorithm>
using namespace std;

//Medium

class Solution {
private:
    vector<vector<int>> edges;          // 存储有向图
    vector<int> indeg;                  // 存储每个节点的入度
    vector<int> result;                 // 存储答案

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) 
        {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        // 将所有入度为 0 的节点放入队列中
        for (int i = 0; i < numCourses; ++i) 
        {
            if (indeg[i] == 0) 
            {
                q.push(i);
            }
        }

        while (!q.empty()) 
        {
            int u = q.front();              // 从队首取出一个节点
            q.pop();
            result.push_back(u);            // 放入答案中
            for (int v: edges[u]) 
            {
                --indeg[v];
                if (indeg[v] == 0)          // 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了 
                {
                    q.push(v);
                }
            }
        }
        if (result.size() != numCourses) 
        {
            return {};
        }
        return result;
    }
};