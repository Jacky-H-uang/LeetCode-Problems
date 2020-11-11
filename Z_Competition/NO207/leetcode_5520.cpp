//          5520. 拆分字符串使唯一子字符串的数目最大
//
// 给你一个字符串 s ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。
// 字符串 s 拆分后可以得到若干 非空子字符串 ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 唯一的 。
// 注意：子字符串 是字符串中的一个连续字符序列。
//
//
// 示例 1：
// 输入：s = "ababccc"
// 输出：5
// 解释：一种最大拆分方法为 ['a', 'b', 'ab', 'c', 'cc'] 。
//       像 ['a', 'b', 'a', 'b', 'c', 'cc'] 这样拆分不满足题目要求，因为其中的 'a' 和 'b' 都出现了不止一次。
//
// 示例 2：
// 输入：s = "aba"
// 输出：2
// 解释：一种最大拆分方法为 ['a', 'ba'] 。
//
// 示例 3：
// 输入：s = "aa"
// 输出：1
// 解释：无法进一步拆分字符串。
//
// 提示：
// 1 <= s.length <= 16
// s 仅包含小写英文字母


#include<bits/stdc++.h>
using namespace std;

// Medium

// 数据量小可以直接暴力回溯
class Solution {
public:
    unordered_set<string> us;
    int ans = 1;
    void dfs(string s, int c)
    {
        if(s == "")
        {
            ans = max(ans,c);
            return;
        }

        int n = s.size();

        for(int i = 1; i <= n; ++i)
        {
            string L = s.substr(0,i);
            string R = s.substr(i);
            if(us.count(L) != 1)
            {
                us.insert(L);
                dfs(R,c+1);
                us.erase(L);        // 回溯
            }
        }
    }

    int maxUniqueSplit(string s) 
    {
        dfs(s,ans);

        return ans;
    }
};