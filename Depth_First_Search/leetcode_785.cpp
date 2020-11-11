// 给定一个无向图graph，当这个图为二分图时返回true。
// 如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。
// graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。
// 这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。
//
//
// 示例 1:
// 输入: [[1,3], [0,2], [1,3], [0,2]]
// 输出: true
// 解释: 
// 无向图如下:
// 0----1
// |    |
// |    |
// 3----2
// 我们可以将节点分成两组: {0, 2} 和 {1, 3}。
//
// 示例 2:
// 输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
// 输出: false
// 解释: 
// 无向图如下:
// 0----1
// | \  |
// |  \ |
// 3----2
// 我们不能将节点分割成两个独立的子集。
//
//
// 注意:
// graph 的长度范围为 [1, 100]。
// graph[i] 中的元素的范围为 [0, graph.length - 1]。
// graph[i] 不会包含 i 或者有重复的值。
// 图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。



#include<iostream>
#include<vector>
using namespace std;


// Medium
// DFS: 深度优先遍历
class Solution {
private:
    // 染色法所用得颜色分别为：无色、红色、绿色
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    
    // 记录结点颜色
    vector<int> color;
    
    // 记录是否为二分图
    bool valid = true;

public:
    void dfs(int node, int c, const vector<vector<int>>& graph) 
    {
        color[node] = c;

        // 这次遍历中当前节点相邻节点应该涂的颜色
        int cNext = c == RED ? GREEN : RED;

        // 遍历当前节点相邻所有节点
        for (int neighbor: graph[node]) 
        {
            // 如果相邻接点还没涂色，则继续深度优先遍历涂色
            if (color[neighbor] == UNCOLORED) 
            {
                dfs(neighbor, cNext, graph);

                // 判断上面遍历已经确定图不是二分图
                if (!valid) 
                {
                    return;
                }
            }
            // 如果相邻节点已经有颜色，并且跟这次遍历本该涂的颜色不一致，说明不是二分图
            else if (color[neighbor] != cNext) 
            {
                valid = false;
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        valid = true;
        color.assign(n, UNCOLORED);
        for (int i = 0; i < n && valid; ++i) 
        {
            if (color[i] == UNCOLORED) 
            {
                dfs(i, RED, graph);
            }
        }
        return valid;
    }
};