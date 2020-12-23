//                                  387. 字符串中的第一个唯一字符
//
// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
//
//
// 示例：
// s = "leetcode"
// 返回 0
// s = "loveleetcode"
// 返回 2


#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    int firstUniqChar(string s) {
        // 哈希表两遍扫描
        unordered_map<char,int> st;
        for(auto& c : s) {
            st[c]++;
        }
        for(int i = 0; i < s.size(); ++i) {
            if(st[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};