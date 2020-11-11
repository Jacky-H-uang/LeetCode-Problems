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
    // 分析：
    // 用一个队列记录每一个结点的出度和入度的数量
    // 入度为 0 的时候就可以学习这门课程
    // 每学习完一门课程就将它的出度结点的入度减 1
    bool bfs(int numC,vector<vector<int>>& pre)
    {
        int len = pre.size();
        unordered_map<int,vector<int>> hashmap;
        queue<int> q;
        vector<int> Indegree(numC,0);
        for(int i = 0; i < len; ++i)
        {
            int a = pre[i][0];          // 后修课
            int b = pre[i][1];          // 先修课
            
            hashmap[b].push_back(a);         // 存储出度数
            Indegree[a]++;                   // 存储入度数
        }

        for(int i = 0; i < numC; ++i)
        {
            if(Indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int temp = q.front();         // 取出此时可以上的课
            q.pop();
            if(hashmap.find(temp) != hashmap.end())
            {
                for(auto& t : hashmap[temp])
                {
                    Indegree[t]--;
                    if(Indegree[t] == 0 )
                    {
                        q.push(t);
                    }
                }
            }
        }

        for(int i = 0; i < numC; ++i)
        {
            // 说明有环
            if(Indegree[i] != 0)
            {
                return false;
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        return bfs(numCourses,prerequisites);
    }
};


int main()
{
    Solution s;
    vector<vector<int>> arr = {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};
    cout<<s.canFinish(7,arr)<<endl;
    system("pause");
    return 0;
}