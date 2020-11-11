/*                                                  Minimum Window Substring                                            */

// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
//
// Note:
// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// Hard

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int lenS = s.size();
        int lenT = t.size();

        vector<int> winFreq(128);
        vector<int> tFreq(128,0);
        for(auto &ch:t)
        {
            tFreq[ch]++;
        }
        int l = 0;
        int r = 0;
        int minLen = lenS+1;
        int distance = 0;
        int begin = 0;

        while(r < lenS)
        {
            if(tFreq[s[r]] == 0)
            {
                r++;
                continue;
            }
            if(winFreq[s[r]] < tFreq[s[r]])
            {
                distance++;
            }
            winFreq[s[r]]++;
            r++;
            while(distance == lenT)
            {
                if(r-l<minLen)
                {
                    minLen = r-l;
                    begin = l;
                }
                if(tFreq[s[l]] == 0)
                {
                    l++;
                    continue;
                }
                if(winFreq[s[l]] == tFreq[s[l]])
                {
                    distance--;
                }
                winFreq[(int)s[l]]--;
                l++;
            }
        }
        if(minLen == lenS+1)
        {
            return "";
        }
        return s.substr(begin,minLen);
    }
};


int main()
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    Solution s;
    cout<<s.minWindow(S,T)<<endl;
    system("pause");
    return 0;
}