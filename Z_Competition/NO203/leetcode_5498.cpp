//              5498. 石子游戏 V
//
// 几块石子 排成一行 ，每块石子都有一个关联值，关联值为整数，由数组 stoneValue 给出。
// 游戏中的每一轮：Alice 会将这行石子分成两个 非空行（即，左侧行和右侧行）；Bob 负责计算每一行的值，即此行中所有石子的值的总和。
// Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始。
// 只剩下一块石子时，游戏结束。Alice 的分数最初为 0 。
// 返回 Alice 能够获得的最大分数 。
//
//  
// 示例 1：
// 输入：stoneValue = [6,2,3,4,5,5]
// 输出：18
// 解释：在第一轮中，Alice 将行划分为 [6，2，3]，[4，5，5] 。左行的值是 11 ，右行的值是 14 。Bob 丢弃了右行，Alice 的分数现在是 11 。
// 在第二轮中，Alice 将行分成 [6]，[2，3] 。这一次 Bob 扔掉了左行，Alice 的分数变成了 16（11 + 5）。
// 最后一轮 Alice 只能将行分成 [2]，[3] 。Bob 扔掉右行，Alice 的分数现在是 18（16 + 2）。游戏结束，因为这行只剩下一块石头了。
//
//
// 示例 2：
// 输入：stoneValue = [7,7,7,7,7,7,7]
// 输出：28
//
//
// 示例 3：
// 输入：stoneValue = [4]
// 输出：0
//  
//
// 提示：
// 1 <= stoneValue.length <= 500
// 1 <= stoneValue[i] <= 10^6

#include<bits/stdc++.h>
using namespace std;

// Hard


// 区间 DP
// 1: 状态表示
// 2: 状态计算
class Solution {
public:
    vector<int> s;                  // 求前缀和

    // 求区间的前缀和函数
    int get(int l,int r)
    {
        return s[r] - s[l-1];
    }

    int stoneGameV(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();
        s.resize(n+1);

        // 预处理前缀和
        for(int i = 1; i <= n; ++i)
        {
            s[i] = s[i-1] + stoneValue[i-1];
        }

        // 状态数组
        vector<vector<int>> dp(n+1,vector<int>(n+1));
    
        // 动态规划的区间范围
        for(int len = 2; len <= n; ++len)
        {
            // 动态规划的起点
            for(int i = 1; i + len -1 <= n; ++i)
            {
                // 动态规划的终点
                int j = i + len - 1;

                // 记录一下区间内的总和
                int sum = get(i,j);

                // 区间内遍历的指针
                int k = i;         

                // i~k 的和
                int pre = stoneValue[i-1];

                // 记录最大值
                int t = 0;

                // 左区间  <  右区间
                while (pre < sum - pre)
                {
                    if(t < pre + dp[i][k])
                    {
                        t = pre + dp[i][k];
                    }
                    pre += stoneValue[k++];
                }
                
                // 左区间  ==  右区间
                if(pre == sum - pre)
                {
                    if(t < pre + max(dp[i][k],dp[k+1][j]))
                    {
                        t = pre + max(dp[i][k],dp[k+1][j]);
                    }
                    pre += stoneValue[k++];
                }

                // 左区间  >  右区间
                while(k < j)
                {
                    if(t < sum - pre + dp[k+1][j])
                    {
                        t = sum - pre + dp[k+1][j];
                    }
                    pre += stoneValue[k++];
                }
                
                dp[i][j] = t;
            }
        }

        return dp[1][n];
    }
};