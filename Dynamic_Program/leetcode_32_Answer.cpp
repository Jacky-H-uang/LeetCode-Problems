// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
//
// 示例 1:
// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
//
// 示例 2:
// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"


#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

// Hard
// 状态转移方程 dp[i] = 2 + dp[i-1] + dp[i-dp[i-1]-2]
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int len = s.size();
        int res = 0;
        vector<int> dp(len);
        if(len <= 1)
        {
            return 0;
        }
        for(int i=1;i<len;i++)
        {
            if(s[i] == '(')
            {
                dp[i] = 0;
            }
            else
            {
                if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                {
                    if(i-dp[i-1]-2 >= 0)
                    {
                        dp[i] = 2 + dp[i-1] + dp[i-dp[i-1]-2];
                        res = max(dp[i],res);
                    }
                    else
                    {
                        dp[i] = 2 + dp[i-1];
                        res = max(dp[i],res);
                    }
                }
                else
                {
                    dp[i] = 0;
                }
            }
        }
        return res;
    }
};