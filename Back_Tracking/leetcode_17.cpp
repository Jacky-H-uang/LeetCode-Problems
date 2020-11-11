// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
// 1        2       3
//!@#      abc     def
// 
// 4        5       6
//ghi      jkl     mno
//
// 7        8       9
//pqrs     tuv     wxyz 
//
//
// 示例:
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


#include<bits/stdc++.h>
using namespace std;

//Medium

class Solution {
public:
    vector<string> letterCombinations(string digits) {      
        vector<string> ans;
        
        int len = digits.size();
        string str = "";

        // 存号码
        unordered_map<char,string> number;
        function<void()> init = [&]() {
            number['2'] = "abc";
            number['3'] = "def";
            number['4'] = "ghi";
            number['5'] = "jkl";
            number['6'] = "mno";
            number['7'] = "pqrs";
            number['8'] = "tuv";
            number['9'] = "wxyz";
        };

        // DFS
        function<void(int)> dfs = [&](int x){
            if(str.size() == len)
            {
                ans.push_back(str);
                return;
            }

            string temp = number[digits[x]];
            
            for(auto& ch : temp)
            {
                str += ch;
                dfs(x+1);
                str.pop_back();
            }
        };
        
        
        if(len == 0)
        {
            return ans;
        }
        
        init();
        dfs(0);
        
        return ans;
    }
};