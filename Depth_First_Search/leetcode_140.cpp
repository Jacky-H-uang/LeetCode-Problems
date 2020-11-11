//                                  140. Word Break II
//
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
// add spaces in s to construct a sentence where each word is a valid dictionary word. 
// Return all such possible sentences.
//
// Note:
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
//
// Example 1:
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
//
// Example 2:
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
// Example 3:
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []



#include<bits/stdc++.h>
using namespace std;

// Hard

class Solution {
public:
    // 哈希表记录来剪枝
    unordered_map<string,vector<string>> st;

    vector<string> dfs(string s,vector<string>& wordDict)
    {
        if(st.count(s) == 1)        return st[s];
        if(s.empty())               return {""};
        vector<string> ans;
        for(auto& w : wordDict)
        {
            if(s.substr(0,w.size()) != w)   continue;
            
            vector<string> aux = dfs(s.substr(w.size()),wordDict);

            for(auto& a : aux)      ans.push_back(w + (a.empty()?"" : " ") + a);
        }

        st[s] = ans;
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        return dfs(s,wordDict);
    }
};