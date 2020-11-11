// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
// 示例:
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// 说明：
// 所有输入均为小写字母。
// 不考虑答案输出的顺序。


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int len = strs.size();
        vector<vector<string>> ans;
        map<string,vector<string>> hashmap;

        for(int i = 0; i < len; ++i)
        {
            string temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            hashmap[strs[i]].push_back(temp);
        }
        map<string,vector<string>>::iterator it = hashmap.begin();
        for(;it != hashmap.end();it++)
        {
            ans.push_back(it->second);
        } 
        return ans;
    }
};