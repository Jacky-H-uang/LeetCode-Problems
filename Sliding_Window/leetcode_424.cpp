//                                  424. 替换后的最长重复字符
//
// 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。
// 在执行上述操作后，找到包含重复字母的最长子串的长度。
// 注意：字符串长度 和 k 不会超过 10^4。
//
//
// 示例 1：
// 输入：s = "ABAB", k = 2
// 输出：4
// 解释：用两个'A'替换为两个'B',反之亦然。
//
// 示例 2：
// 输入：s = "AABABBA", k = 1
// 输出：4
// 解释：
// 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
// 子串 "BBBB" 有最长重复字母, 答案为 4。


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Sliding Window
        vector<int> cnt(26,0);                  // 一个 memo
        int l = 0 , ans = 0  , maxC = 0;
        for(int i = 0; i < s.size(); ++i) {
            cnt[s[i]-'A'] ++ ;

            // 取当前最大的窗口
            maxC = max(maxC , cnt[s[i] - 'A']);
            // 当前的循环的范围比 窗口 + k大的时候则需要缩短当前的循环
            while(i - l + 1 - maxC > k) {
                cnt[s[l]-'A']--;
                l++;
            }
            ans = max(ans , i - l + 1);
        }

        return ans;
    }
};