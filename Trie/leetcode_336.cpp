//              336. 回文对
//
// 给定一组 互不相同 的单词， 找出所有不同的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。
//  
//
// 示例 1：
// 输入：["abcd","dcba","lls","s","sssll"]
// 输出：[[0,1],[1,0],[3,2],[2,4]] 
// 解释：可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
//
//
// 示例 2：
// 输入：["bat","tab","cat"]
// 输出：[[0,1],[1,0]] 
// 解释：可拼接成的回文串为 ["battab","tabbat"]


#include<bits/stdc++.h>
using namespace std;

// Hard


// 高级数据结构 ： 字典树
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        int n = words.size();
        for(int i = 0; i < n; ++i)
        {
            
        }
    }
};