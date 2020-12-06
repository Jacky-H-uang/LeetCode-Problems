#include<bits/stdc++.h>
using namespace  std;

// Easy

class Solution {
public:
    string interpret(string command) {
        stack<char> stk;
        string ans = "";
        for(auto& c : command) {
            if(c == 'G') {
                ans += 'G';
            }
            else if(c == '(') {
                stk.push(c);
            }
            else if(c == ')') {
                if(stk.top() == '(') {
                    stk.pop();
                    ans += 'o';
                }
                else if(stk.top() == 'l') {
                    stk.pop();
                    stk.pop();
                    ans += 'a';
                    ans += 'l';
                }
            }
            else {
                stk.push(c);
            }
        }

        return ans;
    }
};