// 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。
// 设计一个算法使得这 m 个子数组各自和的最大值最小。
//
// 注意:
// 数组长度 n 满足以下条件:
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
//
// 示例:
// 输入:
// nums = [7,2,5,10,8]
// m = 2
// 输出:
// 18
//
//
// 解释:
// 一共有四种方法将nums分割为2个子数组。
// 其中最好的方式是将其分为[7,2,5] 和 [10,8]，
// 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。


#include<bits/stdc++.h>
using namespace std;

// Hard

class Solution {
public:
    // f[i][j] 表示前 i 个数被划分为 j 个分组 所能得到的最大连续子数组中的最小值
    // 
    //                          i-1
    // 状态转移方程 ： f[i][j] = min {max(f[k][j-1],sub(k+1,j))}
    //                          k=0
    int splitArray(vector<int>& nums, int m) 
    {
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) 
        {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= min(i, m); j++) 
            {
                for (int k = 0; k < i; k++) 
                {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }  
        return (int)f[n][m];
    }
};




int main()
{
    Solution s;
    vector<int> v = {7,2,5,10,8};
    cout<<s.splitArray(v,2)<<endl;
    system("pause");
    return 0;
}