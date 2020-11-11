// Give a string s, count the number of non-empty (contiguous -- 相邻的) substrings that have the same number of 0's and 1's, 
// and all the 0's and all the 1's in these substrings are grouped consecutively.
// Substrings that occur multiple times are counted the number of times they occur.
//
//
// Example 1:
// Input: "00110011"
// Output: 6
// Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
// Notice that some of these substrings repeat and are counted the number of times they occur.
// Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
//
//
// Example 2:
// Input: "10101"
// Output: 4
// Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
//
//
// Note:
// s.length will be between 1 and 50,000.
// s will only consist of "0" or "1" characters.



#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    int countBinarySubstrings(string s)
    {
        int ans = 0;
        int count = 1;
        int len = s.size();

        // 存储连续的相同二进制数字的数目
        vector<int> store;

        for(int i = 1; i < len; ++i)
        {
            if(s[i-1] == s[i])
            {
                count++;
            }
            else
            {
                store.push_back(count);   
                count = 1;
            }
        }

        store.push_back(count);


        for(int i = 1; i < store.size(); ++i)
        {
            ans += min(store[i-1],store[i]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.countBinarySubstrings("00100")<<endl;
    system("pause");
    return 0;
}