// 763. Partition Labels
// A string S of lowercase English letters is given. 
// We want to partition this string into as many parts as possible so that each letter appears in at most one part, 
// and return a list of integers representing the size of these parts.
//
//
// Example 1:
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
//
//
// Note:
// S will have length in range [1, 500].
// S will consist of lowercase English letters ('a' to 'z') only.


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.size();
        vector<int> ans;
        int p1 = 0;
        int p2 = 0;
        unordered_map<char,int> cnt;

        for(int i = 0; i < len; ++i) {
            cnt[S[i]] = i; 
        }

        // 但遍历的索引和这个字符的最后出现位置重合的时候就可以添加进来
        for(int i = 0; i < len; ++i) {
            p2 = max(p2 , cnt[S[i]]);
            if(i == p2)
            {
                ans.push_back(p2 - p1 + 1);
                p1 = i + 1;
            }
        }

        return ans;
    }
};