// 有一堆石头，每块石头的重量都是正整数。
// 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
// 如果 x == y，那么两块石头都会被完全粉碎；
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
// 最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
//
//  
// 示例：
// 输入：[2,7,4,1,8,1]
// 输出：1
// 解释：
// 组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
// 组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
// 组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
// 组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
//  
//
// 提示：
// 1 <= stones.length <= 30
// 1 <= stones[i] <= 1000

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;

//转换成01背包问题，求两堆石头的最小差值。由于石头总和为sum.则问题转换成了
//背包最多装sum / 2的石头,stones数组里有一大堆石头。求如何装能装下最多重量石头。
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int x = sum/2+1;
        int len = stones.size();
        vector<vector<int>> dp(len+1,vector<int>(x));
        for(int i=1;i<len;i++)
        {
            for(int j=1;j<x;j++)
            {
                if(stones[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j-stones[i-1]]+stones[i-1],dp[i-1][j]); 
                }
            }
        }
        return sum - 2 * dp[len][x-1];
    } 
};

int main()
{
	vector<int> v = {1,1,4,2,2};
	Solution s;
	cout<<s.lastStoneWeightII(v)<<endl;
	system("pause");
    return 0;
}