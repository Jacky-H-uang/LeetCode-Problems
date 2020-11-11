// 925. Long Pressed Name
// Your friend is typing his name into a keyboard.  
// Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
// You examine the typed characters of the keyboard.  
// Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
//
//
// Example 1:
// Input: name = "alex", typed = "aaleex"
// Output: true
// Explanation: 'a' and 'e' in 'alex' were long pressed.
//
//
// Example 2:
// Input: name = "saeed", typed = "ssaaedd"
// Output: false
// Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
//
//
// Example 3:
// Input: name = "leelee", typed = "lleeelee"
// Output: true
//
//
// Example 4:
// Input: name = "laiden", typed = "laiden"
// Output: true
// Explanation: It's not necessary to long press any character.
//
//
// Constraints:
// 1 <= name.length <= 1000
// 1 <= typed.length <= 1000
// The characters of name and typed are lowercase letters.


#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name[0] != typed[0])     return false;
        int p1 = 1;
        int p2 = 1;
        int n1 = name.size();
        int n2 = typed.size();
        while(p1 < n1 || p2 < n2)
        {
            if(p1 == n1)
            {
                if(typed[p2] != typed[p2-1])        return false;
                p2++;
            }
            if(name[p1] != typed[p2])
            {
                if(typed[p2] != typed[p2-1])        return false;

                else
                {
                   p2++;
                   continue; 
                }
            }
            p1++;
            p2++;
        }

        return true;
    }
};