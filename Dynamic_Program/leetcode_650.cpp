/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 *
 * https://leetcode-cn.com/problems/2-keys-keyboard/description/
 *
 * algorithms
 * Medium (49.71%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 19.1K
 * Testcase Example:  '3'
 *
 * 最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：
 * 
 * 
 * Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
 * Paste (粘贴) : 你可以粘贴你上一次复制的字符。
 * 
 * 给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n 个 'A' 的最少操作次数。
 * 
 * 示例 1:
 * 输入: 3
 * 输出: 3
 * 解释:
 * 最初, 我们只有一个字符 'A'。
 * 第 1 步, 我们使用 Copy All 操作。
 * 第 2 步, 我们使用 Paste 操作来获得 'AA'。
 * 第 3 步, 我们使用 Paste 操作来获得 'AAA'。
 * 
 * 说明:
 * 
 * n 的取值范围是 [1, 1000] 。
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

// 分解素数的题目
// 状态转移方程 dp[n] = dp[n/i] + i         (n%i == 0)

// @lc code=start
class Solution {
public:
    int minSteps(int n) 
    {
        int res = 0;
        for(int i=2;i<=n;i++)
        {
            while(n%i == 0)
            {
                res += i;
                n = n/i;
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout<<s.minSteps(8)<<endl;
    system("pause");
    return 0;
}