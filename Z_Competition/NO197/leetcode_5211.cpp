// 5211. 概率最大的路径
//
// 给你一个由 n 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，
// 其中 edges[i] = [a,    b] 表示连接节点 a 和 b 的一条无向边，且该边遍历成功的概率为 succProb[i] 。
// 指定两个节点分别作为起点 start 和终点 end ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。
// 如果不存在从 start 到 end 的路径，请 返回 0 。只要答案与标准答案的误差不超过 1e-5 ，就会被视作正确答案。
//
//
// 示例 1：
//          0.2
//      0---------2
//       \       /
//     0.5\     /0.5
//         \   /
//           1
// 输入：n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
// 输出：0.25000
// 解释：从起点到终点有两条路径，其中一条的成功概率为 0.2 ，而另一条为 0.5 * 0.5 = 0.25
//
//
// 示例 2：
//          0.3
//      0---------2
//       \       /
//     0.5\     /0.5
//         \   /
//           1
// 输入：n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
// 输出：0.30000
//
//
// 示例 3：
//          
//      0         2
//       \       
//     0.5\     
//         \   
//           1
// 输入：n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
// 输出：0.00000
// 解释：节点 0 和 节点 2 之间不存在路径
//
// 提示：

// 2 <= n <= 10^4
// 0 <= start, end < n
// start != end
// 0 <= a, b < n
// a != b
// 0 <= succProb.length == edges.length <= 2*10^4
// 0 <= succProb[i] <= 1
// 每两个节点之间最多有一条边


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>
#include<math.h>
using namespace std;

// Medium

struct DIJ
{
	int n;
	vector <vector <pair <int, double> > > v;
	
	void Init(int n) 
    {
		this->n = n;
		v.clear();
        v.resize(n);
		for (int i = 0; i < n; i++) 
        {
			v[i].clear();
		}
	}
	
	void Add(int a, int b, double c) 
    {
		v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
	}
	
	void GetDist(int st, vector <double> &dist) 
    {
        dist.resize(n);
		priority_queue <pair <double, int> > q;
		for (int i = 0; i < n; i++) 
        {
			dist[i] = 0;
		}
		dist[st] = 1;
		q.push(make_pair(1, st));
		while (q.size() > 0) {
			int now = q.top().second;
			if (fabs(dist[now] - q.top().first) > 1e-9) 
            {
				q.pop();
				continue;
			}
			q.pop();
			for (int i = 0; i < v[now].size(); i++) 
            {
				int nxt = v[now][i].first;
                double value = v[now][i].second;
                //printf("%f %f\n", dist[now], value);
				if (dist[now] * value > dist[nxt]) 
                {
					dist[nxt] = dist[now] * value;
					q.push(make_pair(dist[nxt], nxt));
				}
			}
		}
		return;
	}
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int s, int t) 
    {
        int m = e.size();
        DIJ dij;
        dij.Init(n);
        for (int i = 0; i < m; i++) 
        {
            int a = e[i][0];
            int b = e[i][1];
            double c = p[i];
            dij.Add(a, b, c);
        }
        vector <double> dist;
        dist.resize(n + 1);
        dij.GetDist(s, dist);
        return dist[t];
    }
};