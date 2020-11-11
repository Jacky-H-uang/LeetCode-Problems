/*				Longest Palindromic Substring			*/

//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
// Input: "cbbd"
// Output: "bb"


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Medium

// Dynamic Program
// 状态转移方程 : dp[i][j] = dp[i+1][j-1] ^ (s[i] == s[j]);
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int len = s.size();
        vector<vector<int>> dp(len,vector<int>(len,0));
        int start = 0;
        int maxLen = 1;
        for(int j = 1;j<len;j++)
        {
            for(int i=0;i<j;i++)
            {
                if(s[i] != s[j])
                {
                    dp[i][j] == 0;
                }
                else if(j-i<3)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j] && j-i+1 > maxLen)
                {
                    maxLen = j-i+1;
                    start = i;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};

int main()
{
    string s = "babad";
    Solution sl;
    string str = sl.longestPalindrome(s);
    cout<<str<<endl;  
    system("pause");
    return 0;
}
