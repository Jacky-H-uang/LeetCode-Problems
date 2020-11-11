//          301. 删除无效的括号
//
// 删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。
// 说明: 输入可能包含了除 ( 和 ) 以外的字符。
//
// 示例 1:
// 输入: "()())()"
// 输出: ["()()()", "(())()"]
//
// 示例 2:
// 输入: "(a)())()"
// 输出: ["(a)()()", "(a())()"]
//
// 示例 3:
// 输入: ")("
// 输出: [""]

#include<bits/stdc++.h>
using namespace std;

// Hard

// 记忆化搜索
class Solution {
public:
    vector<string> ans;
    
    /**
     * @param s         -字符串
     * @param u         -枚举到那个字符
     * @param path      -当前遍历的字符串
     * @param cnt       -当前左括号减去右括号的数量
     * @param L         -当前还可以删除多少个左括号
     * @param R         -当前还可以删除多少个右括号
     */
    void dfs(string& s,int u,string path,int cnt,int L,int R)
    {
        // s搜到字符串结尾
        if(u == s.size())
        {
            if(cnt == 0)
            {
                ans.push_back(path);
                return;
            }
        }

        if(s[u] != '(' && s[u] != ')')
        {
            dfs(s , u+1 , path+s[u] , cnt , L , R);
        }

        else if(s[u] == '(')
        {
            int k = u;
            while(k < s.size() && s[k] == '(') k++;         // 枚举当前连续的左括号数量
            L -= k-u;                                       // 先全部删除左括号
            for(int i = k-u; i >= 0; i--)
            {
                if(L >=0 )
                {
                    // 说明当前还需要删除左括号，所以继续搜索
                    dfs(s,k,path,cnt,L,R);
                }

                path += '(';            // 将不用删除的左括号添加回来
                cnt++;
                L++;
            } 
        }
        else if(s[u] == ')')
        {
            int k = u;
            while(k < s.size() && s[k] == ')')  k++;        // 枚举当前连续的右括号的数量
            R -= k-u;                                       // 先删除全部的右括号
            for(int i = k-u;i >=0; --i)
            {
                if(cnt >= 0 && R >= 0)
                {
                    // 说明当前含需要删除右括号，所以继续搜索
                    dfs(s,k,path,cnt,L,R);
                }

                path += ')';                // 将不用删除的右括号添加回来
                cnt--;
                R++;
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) 
    {
        int L = 0;          // 当前左括号数量 - 右括号数量
        int R = 0;          // 当前要删除多少个右括号

        for(auto& c : s)
        {
            if(c == '(')
            {
                L++;
            }
            else if(c == ')')
            {
                if(L == 0)
                {
                    R++;
                }
                else
                {
                    L--;
                }
            }
        }

        dfs(s,0,"",0,L,R);
        return ans;
    }
};