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
    int longestValidParentheses(string s) 
    {
        int res = 0;
        int count = 0;
        int len = s.size();
        stack<int> st;
        vector<bool> v(len,0);
        if(len <= 1)
        {
            return 0;
        }
        for(int i=0;i<len;i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(st.empty())
                {
                    v[i] = 1;
                }
                else
                {
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
            v[st.top()] = 1;
            st.pop();
        }
        for(int i=0;i<len;i++)
        {
            if(v[i] == 0)
            {
                count++;
            }
            else
            {
                res = max(count,res);
                count = 0;
            }
        }
        res = max(count,res);
        return res;
    }
};