// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
// 说明:
// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
//
// 示例 1:
// 输入:
// s = "aa"
// p = "a"
// 输出: false
// 解释: "a" 无法匹配 "aa" 整个字符串。
//
// 示例 2:
// 输入:
// s = "aa"
// p = "a*"
// 输出: true
// 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
//
// 示例 3:
// 输入:
// s = "ab"
// p = ".*"
// 输出: true
// 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
//
// 示例 4:
// 输入:
// s = "aab"
// p = "c*a*b"
// 输出: true
// 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
//
// 示例 5:
// 输入:
// s = "mississippi"
// p = "mis*is*p*."
// 输出: false

#include<iostream>
#include<string>
#include <vector>
using namespace std;

// Hard

class Solution1              // 1.递归回溯法
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
        {
            return s.empty();
        }
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');        
        if(p[1] == '*')
        {
            return isMatch(s,p.substr(2)) || (first_match && isMatch(s.substr(1),p)); 
        }
        else
        {
            return first_match && isMatch(s.substr(1),p.substr(1));
        }
    }
};


class Solution2                     //动态规划
{
    public:
    bool first_match(string s,string p,int i,int j)
    {
        return s[i] == p[j] || p[j] == '.';
    }
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1));           //dp[i][j]表示：s 的前 i 个字符和 p 的前 j 个字符是否匹配
        dp[0][0] = true;
        for(int j = 2;j <= p.size();j++)                                        //初始化 dp[0][]
        {
            dp[0][j] = p[j-1] == '*' && dp[0][j-2];
        }
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<p.size();j++)
            {
                if(p[j] == '*')
                {
                    dp[i+1][j+1] = dp[i+1][j-1] || first_match(s,p,i,j-1) && dp[i][j+1];
                }
                else
                {
                    dp[i+1][j+1] = first_match(s,p,i,j) && dp[i][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main()
{
    Solution2 ss;
    string s = "aab";
    string p = ".*";
    bool r = ss.isMatch(s,p);
    if(r)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    system("pause");
    return 0;
}