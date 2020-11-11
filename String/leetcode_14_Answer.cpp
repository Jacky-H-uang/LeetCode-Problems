#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = strs.size() ? strs[0] : "";
        for(auto s: strs)
        {
            while(s.substr(0, r.size()) != r)           //如果不相等 就减少一个字串的截取 / 相等的话就继续遍历直到完
            {
                r = r.substr(0, r.size() - 1);
                if(r == "") return r;
            }
        }
        return r;
    }
};
