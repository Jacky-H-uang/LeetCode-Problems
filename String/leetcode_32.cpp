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

class Solution {
public:
    // 正向逆向结合法
    int positive(string s)
    {
        int len = s.size();
        int left = 0;
        int right = 0;
        int max_length_pos = 0;
        int max_length = 0;
        for(int i = 0;i<len;i++)
        {
            if(s[i] == '(')
            {
                left++;
            }
            if(s[i] == ')')
            {
                right++;
            }
            if(left == right)
            {
                max_length_pos = 2*left;
            }
            if(left < right)
            {
                left = 0;
                right = 0;
                max_length = max(max_length,max_length_pos);
            }
        }
        return max(max_length,max_length_pos);
    }
    int negative(string s)
    {
        int len = s.size();
        int left = 0;
        int right = 0;
        int max_length_neg = 0;
        int max_length = 0;
        for(int i = len-1;i>=0;i--)
        {
            if(s[i] == '(')
            {
                left++;
            }
            if(s[i] == ')')
            {
                right++;
            }
            if(left == right)
            {
                max_length_neg = 2*left;
            }
            if(left > right)
            {
                left = 0;
                right = 0;
                max_length = max(max_length,max_length_neg);
            }
        }
        return max(max_length,max_length_neg);
    }
    int longestValidParentheses(string s) 
    {
        if(s.size() <= 1)
        {
            return 0;
        }
        return max(positive(s),negative(s));
    }
};