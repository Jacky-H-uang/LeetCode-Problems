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
#include<algorithm>
#include<map>
#include<string>
using namespace std;

//

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        map <char,int> s_map;
        int first = 0;
        int last = 0;
        int len = 0;
        int result = 0;
        while(last<n)
        {
            char tmp = s[last];
            if(s_map.find(tmp)!= s_map.end() && s_map[tmp]>=first)
            {
                first = s_map[tmp] + 1;
                len = last - first;
            }
            s_map[tmp] = last;
            last++;
            len = last - first;
            result = max(result,len);
        }
        return result;
    }
};


int main()
{
    Solution s;
    string x = "abcabcbb";
    int y = s.lengthOfLongestSubstring(x);
    cout<<y<<endl;
    system("pause");
    return 0;
}