// 459. 重复的子字符串
//
//
// 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
//
//
// 示例 1:
// 输入: "abab"
// 输出: True
// 解释: 可由子字符串 "ab" 重复两次构成。
//
//
// 示例 2:
// 输入: "aba"
// 输出: False
//
//
// 示例 3:
// 输入: "abcabcabcabc"
// 输出: True
// 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)


#include<bits/stdc++.h>
using namespace std;

// Easy


// KMP 算法
class Solution {
public:
    bool kmp(const string& query, const string& pattern) 
    {
        int n = query.size();

        int m = pattern.size();
        
        vector<int> fail(m, -1);
        for (int i = 1; i < m; ++i) 
        {
            int j = fail[i - 1];

            while (j != -1 && pattern[j + 1] != pattern[i]) 
            {
                j = fail[j];
            }

            if (pattern[j + 1] == pattern[i]) 
            {
                fail[i] = j + 1;
            }
        }

        int match = -1;
        
        for (int i = 1; i < n - 1; ++i) 
        {
            while (match != -1 && pattern[match + 1] != query[i]) 
            {
                match = fail[match];
            }
            if (pattern[match + 1] == query[i]) 
            {
                ++match;
                if (match == m - 1) 
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) 
    {
        return kmp(s + s, s);
    }
};