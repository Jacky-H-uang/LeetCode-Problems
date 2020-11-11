// 实现 strStr() 函数。
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
//
// 示例 1:
// 输入: haystack = "hello", needle = "ll"
// 输出: 2
//
// 示例 2:
// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1
//
// 说明:
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

#include<iostream>
#include<string>
using namespace std;

//Easy
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int len1 = haystack.size();
        int len2 = needle.size();
        if(haystack == needle && len1 == len2)
        {
            return 0;
        }
        int t = len1-len2;
        int i = 0;
        while (i<=t)
        {
            if(haystack.substr(i,len2) == needle)
            {
                return i;
            }
            i++; 
        }
        return -1;
    }
};


int main()
{
    Solution s;
    string h = "mississpx";
    string n = "x";
    int r = s.strStr(h,n);
    cout<<r<<endl;
    system("pause");
    return 0;
}