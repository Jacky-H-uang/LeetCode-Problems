//      647. Palindromic Substrings
//
// Given a string, your task is to count how many palindromic substrings in this string.
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
//
// Example 1:
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
//  
//
// Example 2:
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//  
//
// Note:
// The input string length won't exceed 1000.



#include<bits/stdc++.h>
using namespace std;

// Medium

// 中心扩展法
class Solution {
public:
    int countSubstrings(string s) 
    {
        int len = s.size();
        int ans = 0;

        function<void(int,int)> helper = [&] (int l,int r)
        {
            while(l >= 0 && r < len && s[l] == s[r])
            {
                ans++;
                l--;
                r++;
            }
        };

        for(int i = 0; i < len; ++i)
        {
            helper(i,i);
            helper(i,i+1);
        }

        return ans;
    }
};