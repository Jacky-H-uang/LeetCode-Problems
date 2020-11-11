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

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

//Medium

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int>m(256,-1);          //把 向量 m 当作字典;  原理为hashmap
        int left = -1;
        int res = 0;
        int len = s.size();
        for(int i=0;i<len;i++)
        {
            left = max(left,m[s[i]]);
            m[s[i]] = i;
            res = max(res,i-left);
        }
        return res;
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