// 214. 最短回文串
//
// 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
//
// 示例 1:
// 输入: "aacecaaa"
// 输出: "aaacecaaa"
//
// 示例 2:
// 输入: "abcd"
// 输出: "dcbabcd"


#include<bits/stdc++.h>
using namespace std;

// Hard

// s : aacecaaa
// s' : aaaceca
// s1 : a
// s2 : acecaaa


class Solution {
public:
    string shortestPalindrome(string s) 
    {
        int len = s.size();
        int i = len-1;
        string ans = s;
        while(i >= 0)
        {
            string t1 = s.substr(0,i+1);
            string t2 = t1;
            reverse(t1.begin(),t1.end());

            string t3 = s.substr(i+1,len-i);
            reverse(t3.begin(),t3.end());

            if(t1 == t2)
            {
                ans = t3+s;
                return ans;
            }
            i--;
        }

        reverse(s.begin(),s.end());
        return s;
    }
};