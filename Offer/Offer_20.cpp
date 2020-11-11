// 剑指 Offer 20. 表示数值的字符串
//
//
// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。


#include<bits/stdc++.h>
using namespace std;

// Medium

// DFA 有限自动机
class Solution {
public:
    bool isNumber(string s) 
    {
        int n = s.size();
        int index = -1;
        bool hasDot = false,hasE = false,hasOp = false,hasNum = false;

        while(index<n && s[++index]==' ');
        
        while(index<n)
        {
            if('0'<=s[index] && s[index]<='9')
            {
                hasNum = true;
            }
            else if(s[index]=='e' || s[index]=='E')
            {
                if(hasE || !hasNum) return false;
                hasE = true;
                hasOp = false;hasDot = false;hasNum = false;
            }
            else if(s[index]=='+' || s[index]=='-')
            {
                if(hasOp || hasNum || hasDot) return false;
                hasOp = true;
            }
            else if(s[index]=='.')
            {
                if(hasDot || hasE) return false;
                hasDot = true;
            }
            else if(s[index]==' ')
            {
                break;
            }
            else
            {
                return false;
            }

            ++index;
        }

        while(index<n && s[++index]==' ');

        return hasNum && index==n;
    }
};