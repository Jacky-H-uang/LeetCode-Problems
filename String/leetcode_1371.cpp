/*              Find the Longest Substring Containing Vowels in Even Counts         */

// Given the string s, return the size of the longest substring containing each vowel an even number of times. 
// That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
//  
// Example 1:
// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
//
// Example 2:
// Input: s = "leetcodeisgreat"
// Output: 5
// Explanation: The longest substring is "leetc" which contains two e's.
//
// Example 3:
// Input: s = "bcbcbc"
// Output: 6
// Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
//  
// Constraints:
// 1 <= s.length <= 5 x 10^5
// s contains only lowercase English letters.


#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Medium


class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        int res = 0;
        int status = 0;
        int len = s.size();
        vector<int> pos(1<<5,-1);               // 32 位 存储 00000 ~ 11111
        pos[0] = 0;
        for(int i=0;i<len;i++)
        {
            if(s[i] == 'a')
            {
                status ^= 1<<0;                 // ^ 为 xor 运算
            }
            else if(s[i] == 'e')
            {
                status ^= 1<<1;
            }
            else if(s[i] == 'i')
            {
                status ^= 1<<2;
            }
            else if(s[i] == 'o')
            {
                status ^= 1<<3;
            }
            else if(s[i] == 'u')
            {
                status ^= 1<<4;
            }
            if(~pos[status])
            {
                res = max(res,i+1-pos[status]);
            }
            else
            {
                pos[status] = i+1;
            }
        }
        return res;
    }
};


int main()
{
    string a = "leetcodeisgreat";
    Solution s;
    cout<<s.findTheLongestSubstring(a)<<endl;
    system("pause");
    return 0;
}