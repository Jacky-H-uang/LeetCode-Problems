//                                          402. Remove K Digits
// Given a non-negative integer num represented as a string, 
// remove k digits from the number so that the new number is the smallest possible.
//
// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
//
// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//
// Example 2:
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//
// Example 3:
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    // 利用栈来判断来贪心的删除元素
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto& digit: num) 
        {
            while (stk.size() > 0 && stk.back() > digit && k) 
            {
                stk.pop_back();
                k -= 1;
            }
            stk.push_back(digit);
        }

        for (; k > 0; --k) {
            stk.pop_back();
        }

        string ans = "";
        bool isLeadingZero = true;
        for (auto& digit: stk) {
            if (isLeadingZero && digit == '0')      continue;
            isLeadingZero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};