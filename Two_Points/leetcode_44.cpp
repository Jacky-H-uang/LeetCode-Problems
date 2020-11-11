// 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
// '?' 可以匹配任何单个字符。
// '*' 可以匹配任意字符串（包括空字符串）。
// 两个字符串完全匹配才算匹配成功。
//
// 说明:
// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
//
//
// 示例 1:
// 输入:
// s = "aa"
// p = "a"
// 输出: false
// 解释: "a" 无法匹配 "aa" 整个字符串。
//
// 示例 2:
// 输入:
// s = "aa"
// p = "*"
// 输出: true
// 解释: '*' 可以匹配任意字符串。
//
// 示例 3:
// 输入:
// s = "cb"
// p = "?a"
// 输出: false
// 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
//
// 示例 4:
// 输入:
// s = "adceb"
// p = "*a*b"
// 输出: true
// 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
//
// 示例 5:
// 输入:
// s = "acdcb"
// p = "a*c?b"  
// 输出: false

// a      b      d      c      d      a      a      b
//                                        temp/ls
//
// a      ?      d      *      a      a      b
//                     begin         lp

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    // 双指针关键在于要回溯
    // 因为可能 * 扫描过程中有两个相同的，此时就要回溯
    bool isMatch(string s, string p) 
    {
        int l_s = 0;
        int l_p = 0;
        int len_s = s.size();
        int len_p = p.size();
        int begin = -1;
        int temp = 0;
        while(l_s < len_s)
        {
            if(l_p < len_p && (s[l_s] == p[l_p] || p[l_p] == '?'))
            {
                l_s++;
                l_p++;
            }
            else if(l_p < len_p && p[l_p] == '*')
            {
                begin = l_p;
                temp = l_s; 
                l_p++;
            }
            else if(begin != -1)
            {
                l_p = begin+1;
                temp++;
                l_s = temp;
            }
            else
            {
                return false;
            }
        }
        while(l_p < len_p)
        {
            if(p[l_p] != '*')
            {
                return false;
            }
            l_p++;
        }
        return true;
    }
};