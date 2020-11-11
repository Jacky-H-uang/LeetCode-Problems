/*                                               Excel Sheet Column Number                                            */

// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
//     ...
//
// Example 1:
// Input: "A"
// Output: 1
//
// Example 2:
// Input: "AB"
// Output: 28
//
// Example 3:
// Input: "ZY"
// Output: 701


#include<iostream>
#include<string>
#include<math.h>
using namespace std;

// Easy

// 先对 64 取余
// 26 进制转换为 10 进制
class Solution {
public:
    int titleToNumber(string s) 
    {
        int sum = 0;
        int len = s.size();
        for(int i=0;i<len;i++)
        {
            int t = int(s[i]);
            sum += (t%64)*pow(26,len-i-1);
        }
        return sum;
    }
};


int main()
{
    Solution s;
    string a = "AB";
    cout<<s.titleToNumber(a)<<endl;
    system("pause");
    return 0;
}