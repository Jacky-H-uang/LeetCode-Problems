//              1575. 统计所有可行路径
//
// 给你一个 互不相同 的整数数组，其中 locations[i] 表示第 i 个城市的位置。
// 同时给你 start，finish 和 fuel 分别表示出发城市、目的地城市和你初始拥有的汽油总量
// 每一步中，如果你在城市 i ，你可以选择任意一个城市 j ，满足  j != i 且 0 <= j < locations.length ，并移动到城市 j 。
// 从城市 i 移动到 j 消耗的汽油量为 |locations[i] - locations[j]|，|x| 表示 x 的绝对值。
// 请注意， fuel 任何时刻都 不能 为负，且你 可以 经过任意城市超过一次（包括 start 和 finish ）。
// 请你返回从 start 到 finish 所有可能路径的数目。
// 由于答案可能很大， 请将它对 10^9 + 7 取余后返回。
//  
//
// 示例 1：
// 输入：locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
// 输出：4
// 解释：以下为所有可能路径，每一条都用了 5 单位的汽油：
// 1 -> 3
// 1 -> 2 -> 3
// 1 -> 4 -> 3
// 1 -> 4 -> 2 -> 3
//
// 示例 2：
// 输入：locations = [4,3,1], start = 1, finish = 0, fuel = 6
// 输出：5
// 解释：以下为所有可能的路径：
// 1 -> 0，使用汽油量为 fuel = 1
// 1 -> 2 -> 0，使用汽油量为 fuel = 5
// 1 -> 2 -> 1 -> 0，使用汽油量为 fuel = 5
// 1 -> 0 -> 1 -> 0，使用汽油量为 fuel = 3
// 1 -> 0 -> 1 -> 0 -> 1 -> 0，使用汽油量为 fuel = 5
//
// 示例 3：
// 输入：locations = [5,2,1], start = 0, finish = 2, fuel = 3
// 输出：0
// 解释：没有办法只用 3 单位的汽油从 0 到达 2 。因为最短路径需要 4 单位的汽油。
//
// 示例 4 ：
// 输入：locations = [2,1,5], start = 0, finish = 0, fuel = 3
// 输出：2
// 解释：总共有两条可行路径，0 和 0 -> 1 -> 0 。
//
// 示例 5：
// 输入：locations = [1,2,3], start = 0, finish = 2, fuel = 40
// 输出：615088286
// 解释：路径总数为 2615088300 。将结果对 10^9 + 7 取余，得到 615088286 。
//  
//
// 提示：
// 2 <= locations.length <= 100
// 1 <= locations[i] <= 10^9
// 所有 locations 中的整数 互不相同 。
// 0 <= start, finish < locations.length
// 1 <= fuel <= 200


#include<bits/stdc++.h>
using namespace std;

// Hard

// 记忆化搜索 或者（动态规划）
// dp[pos][fuel]  表示当前位置，剩余油fuel，去目标位置的路劲条数
// 如果下一站为 i 的话，dp[pos][fuel] = sum(dp[i][fuel-abs(locations[pos]-locations[i])])       i 为当前位置能去的下一站
class Solution {
public:
    static constexpr int MOD = 1000000007;
    vector<vector<int>> dp;
    int n;

    int dfs(vector<int>& locations,int pos,int finish,int fuel)
    {
        // 表示已经搜索过 所以直接返回
        if(dp[pos][fuel] != -1)
        {
            return dp[pos][fuel];
        }

        // 标记正在搜索
        dp[pos][fuel] = 0;


        for(int i = 0; i < n; ++i)
        {
            if(pos == i)    continue;
            if(abs(locations[pos] - locations[i]) <= fuel)
            {
                dp[pos][fuel] += dfs(locations,i,finish,fuel-abs(locations[pos] - locations[i]));
                dp[pos][fuel] %= MOD;
            }
        }

        if(pos == finish)
        {
            dp[pos][fuel] += 1;
            dp[pos][fuel] %= MOD;
        }

        return dp[pos][fuel];
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        dp.resize(locations.size(),vector<int>(fuel+1,-1));
        this->n = locations.size();

        return dfs(locations,start,finish,fuel);
    }
};