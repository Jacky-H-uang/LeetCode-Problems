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

class Solution {
public:
    int coumputeLen(string s,int l,int r)
    {
        while(l>=0 && r<s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) 
    {
        int start = 0;
        int end = 0;
        int length = s.size();
        if (length < 1)
		{
			return "";
		}
        for(int i=0;i<length;i++)
        {
            int len1 = coumputeLen(s,i,i);
            int len2 = coumputeLen(s,i,i+1);    
            int len = max(len1,len2);
            if(len-1 >= end-start)
            {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start,end-start+1);
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
