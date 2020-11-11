//                  844. Backspace String Compare
//
// Given two strings S and T, return if they are equal when both are typed into empty text editors. 
// # means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.
//
// Example 1:
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
//
// Example 2:
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
//
// Example 3:
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
//
// Example 4:
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
//
// Note:
// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
//
// Follow up:
// Can you solve it in O(N) time and O(1) space?


#include<bits/stdc++.h>
using namespace std;

//Easy

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stS;
        stack<char> stT;
        
        // 遇到 # 且栈不为空的时候就删除栈中的一个元素
        for(auto& c : S) {
            if(c != '#')                    stS.push(c);
            if(c == '#' && !stS.empty())    stS.pop();
        }
        for(auto& c : T) {
            if(c != '#')                    stT.push(c);
            if(c == '#' && !stT.empty())    stT.pop();                          
        }

        int size = stS.size();
        if(size != stT.size())      return false;

        while(size--) {
            char c1 = stS.top();
            char c2 = stT.top();
            stS.pop();
            stT.pop();
            if(c1 != c2)        return false;
        }

        return true;
    }
};