/**给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 示例1:
 *输入: "abcabcbb"
 *输出: 3 
 *解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *示例 2:
 *
 *输入: "bbbbb"
 *输出: 1
 *解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *示例 3:
 *
 *输入: "pwwkew"
 *输出: 3
 *解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *    请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */


#include<bits/stdc++.h>
using namespace std;

//Medium

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.size();
        int ans = 1;
        int l = 0;
        int r = 0;
        unordered_map<char,int> um;

        if(len <= 0)
        {
            return 0;
        }

        while(r < len)
        {
            if(um.find(s[r]) != um.end())
            {
                if(l <= um[s[r]])
                {
                    ans = max(ans,r-l);
                    l = um[s[r]] + 1;
                    um[s[r]] = r;
                    r++;
                }
                else
                {
                    ans = max(ans,r-l+1);
                    um[s[r]] = r;
                    r++;
                }
            }
            else
            {
                ans = max(ans,r-l+1);
                um[s[r]] = r;
                r++;
            }
        }
        return ans;
    }
};



int main()
{
    string ms = "aabbcc";
    Solution s;
    int c =s.lengthOfLongestSubstring(ms);
    cout<<c<<endl;

    system("pause");
    return 0;
}