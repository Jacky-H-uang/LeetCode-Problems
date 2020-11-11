//          Valid Palindrome II

// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
//
// Example 1:
// Input: "aba"
// Output: True
//
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
//
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 5000


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// Easy

class Solution {
public:
    bool validPalindrome(string s) 
    {
        int len = s.size();
        int l = 0;
        int r = len-1;
        while(l<r)
        {
            if(s[l] != s[r])
            {
                bool r1;
                bool r2;
                int x = l;
                x++;

                string t1 = s.substr(x,r-l);
                string t2 = t1;
                reverse(t1.begin(),t1.end());
                r1 = (t1==t2);

                string t3 = s.substr(l,r-l);
                string t4 = t3;
                reverse(t3.begin(),t3.end());
                r2 = (t3==t4);
                return r1||r2;
            }
            l++;
            r--;
        }
        return true;
    }
};


int main()
{
    string a = "abcacdba";
    Solution s;
    if(s.validPalindrome(a))
    {
        cout<<"Y"<<endl;
    }
    else
    {
        cout<<"N"<<endl;
    }
    system("pause");
    return 0;
}