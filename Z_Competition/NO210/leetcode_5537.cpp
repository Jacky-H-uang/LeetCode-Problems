//                      5537. 分割两个字符串得到回文串
//
// 给你两个字符串 a 和 b ，它们长度相同。请你选择一个下标，将两个字符串都在 相同的下标 分割开。
// 由 a 可以得到两个字符串： aprefix 和 asuffix ，满足 a = aprefix + asuffix ，
// 同理，由 b 可以得到两个字符串 bprefix 和 bsuffix ，满足 b = bprefix + bsuffix 。
// 请你判断 aprefix + bsuffix 或者 bprefix + asuffix 能否构成回文串。
// 当你将一个字符串 s 分割成 sprefix 和 ssuffix 时， ssuffix 或者 sprefix 可以为空。
// 比方说， s = "abc" 那么 "" + "abc" ， "a" + "bc" ， "ab" + "c" 和 "abc" + "" 都是合法分割。
// 如果 能构成回文字符串 ，那么请返回 true，否则返回 false 。
// 请注意， x + y 表示连接字符串 x 和 y 。
//
//
// 示例 1：
// 输入：a = "x", b = "y"
// 输出：true
// 解释：如果 a 或者 b 是回文串，那么答案一定为 true ，因为你可以如下分割：
// aprefix = "", asuffix = "x"
// bprefix = "", bsuffix = "y"
// 那么 aprefix + bsuffix = "" + "y" = "y" 是回文串。
//
//
// 示例 2：
// 输入：a = "ulacfd", b = "jizalu"
// 输出：true
// 解释：在下标为 3 处分割：
// aprefix = "ula", asuffix = "cfd"
// bprefix = "jiz", bsuffix = "alu"
// 那么 aprefix + bsuffix = "ula" + "alu" = "ulaalu" 是回文串。
//
//
// 提示：
// 1 <= a.length, b.length <= 105
// a.length == b.length
// a 和 b 都只包含小写英文字母

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    bool Palindrome(string& a,int L,int R) 
    {
        // 判断 L ~ R 的串是否为回文串
        while(L < R && L >= 0 && R < n) 
        {
            if(a[L] != a[R])  return false;
            L++;
            R--;
        }
        
        return true;
    }
    
    bool check(string& a,string& b) 
    {
        int L = 0;
        int R = n-1;
        
        while(L < R && a[L] == b[R])
        {
            L++;
            R--;
        }

        // 判断中间串
        if(L < R)            return (Palindrome(a,L,R) || Palindrome(b,L,R));

        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) 
    {
        n = a.size();
        
        // 判断 a b 串 是否为回文串
        if(Palindrome(a,0,n-1) || Palindrome(b,0,n-1))  return true;
        
        // 分别以 a 串和 b 串为 prefix 来拼接字符串
        return check(a,b) || check(b,a);
    }
};