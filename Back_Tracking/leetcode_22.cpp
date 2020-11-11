// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//
//
// 示例：
// 输入：n = 3
// 输出：[
//        "((()))",
//        "(()())",
//        "(())()",
//        "()(())",
//        "()()()"
//      ]


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        
        function<void(int,int,string)> dfs = [&](int x,int y,string str) {
            if(x > n || y > n)
            {
                return;
            }
            if(x == n && y == n)
            {
                ans.push_back(str);
            }
            
            // 当右括号比左括号多的时候有两种选择 ：
            if(x >= y)
            {
                string temp = str;
                dfs(x+1,y,str + '(');
                dfs(x,y+1,temp + ')');
            }
        };
        
        if(n == 0)
        {
            return ans;
        }
        
        dfs(0,0,"");
        
        return ans;
    }
};