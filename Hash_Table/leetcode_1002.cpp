//                                  1002. Find Common Characters
//
// Given an array A of strings made only from lowercase letters, 
// return a list of all characters that show up in all strings within the list (including duplicates).  
// For example, if a character occurs 3 times in all strings but not 4 times, 
// you need to include that character three times in the final answer.
// You may return the answer in any order.
//
//
// Example 1:
// Input: ["bella","label","roller"]
// Output: ["e","l","l"]
//
//
// Example 2:
// Input: ["cool","lock","cook"]
// Output: ["c","o"]
//
//
// Note:
// 1 <= A.length <= 100
// 1 <= A[i].length <= 100
// A[i][j] is a lowercase letter


#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    vector<string> commonChars(vector<string>& A) 
    {
        vector<string> ans;
        vector<int> cnt(26);
        vector<int> min_ch(26,100001);
        int n = A.size();
        for(int i = 0; i < n; ++i)
        {
            fill(cnt.begin(),cnt.end(),0);              // 每次 cnt 重新计数
            // 第一次计数
            for(auto& x : A[i])
            {
                cnt[x-'a']++;
            }

            // 第二次来找到最小的字符个数
            for(int j = 0; j < 26; ++j)
            {
                min_ch[j] = min(cnt[j],min_ch[j]);
            }
        }

        for(int i = 0; i < 26; ++i)
        {
            while(min_ch[i] > 0)
            {
                ans.emplace_back(1,'a' + i);
                min_ch[i]--;
            }
        }

        return ans;
    }
};