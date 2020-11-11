//  5466. 最多的不重叠子字符串
//
//
// 给你一个只包含小写字母的字符串 s ，你需要找到 s 中最多数目的非空子字符串，满足如下条件：
// 这些字符串之间互不重叠，也就是说对于任意两个子字符串 s[i..j] 和 s[k..l] ，要么 j < k 要么 i > l 。
// 如果一个子字符串包含字符 c ，那么 s 中所有 c 字符都应该在这个子字符串中。
// 请你找到满足上述条件的最多子字符串数目。如果有多个解法有相同的子字符串数目，请返回这些子字符串总长度最小的一个解。可以证明最小总长度解是唯一的。
// 请注意，你可以以 任意 顺序返回最优解的子字符串。
//
//
// 示例 1：
// 输入：s = "adefaddaccc"
// 输出：["e","f","ccc"]
// 解释：下面为所有满足第二个条件的子字符串：
// [
//   "adefaddaccc"
//   "adefadda",
//   "ef",
//   "e",
//   "f",
//   "ccc",
// ]
// 如果我们选择第一个字符串，那么我们无法再选择其他任何字符串，所以答案为 1 。如果我们选择 "adefadda" ，剩下子字符串中我们只可以选择 "ccc" ，它是唯一不重叠的子字符串，所以答案为 2 。
// 同时我们可以发现，选择 "ef" 不是最优的，因为它可以被拆分成 2 个子字符串。所以最优解是选择 ["e","f","ccc"] ，答案为 3 。不存在别的相同数目子字符串解。
//
// 示例 2：
// 输入：s = "abbaccd"
// 输出：["d","bb","cc"]
// 解释：注意到解 ["d","abba","cc"] 答案也为 3 ，但它不是最优解，因为它的总长度更长。
//
//
// 提示：
// 1 <= s.length <= 10^5
// s 只包含小写英文字母。


#include<bits/stdc++.h>
using namespace std;

// Medium



class Solution {
public:
    struct Greedy
    {
        int left;
        int right;
    };
    
    bool cmp(const Greedy g1 ,const Greedy g2)
    {
        if(g1.right == g2.right)
        {
            return g1.left > g2.left;
        }
        return g1.right < g2.right;
    }

    
    vector<string> maxNumOfSubstrings(string s) 
    {
        // 记录每个字母所占的长度
        vector<Greedy> hashmap(26,{-1,-1});

        vector<string> ans;

        for(int i = 0; i < s.size(); ++i)
        {
            if(hashmap[s[i]-'0'].left != -1)
            {
                hashmap[s[i]-'0'].right = i;
                continue;
            }
            hashmap[s[i]-'0'].left = i;
        }

        // 按照其所占长度来从小到大来排序
        sort(hashmap.begin(),hashmap.end(),cmp);
        
        int end = -1;
        for(auto& h : hashmap)
        {
            if(h.left == -1)
            {
                continue;
            }

            if(end == -1 || h.left > end)
            {
                end = h.right;
                ans.push_back(s.substr(h.left,h.right-h.left+1));
            }
        }

        return ans;
    }
};