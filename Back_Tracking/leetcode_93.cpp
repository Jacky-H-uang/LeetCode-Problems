// 93. Restore IP Addresses
//
// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.
//
//
// Example:
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]



#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
private:
    static constexpr int SEG_COUNT = 4;     // 4 位 IP 地址

private:
    vector<string> ans;             // 存储返回答案
    vector<int> segments;           // 存储每一次搜索的 id 地址的数字

public:
    void dfs(const string& s, int segId, int segStart) {
        // 如果找到了 4 段 IP 地址并且遍历完了字符串，那么就是一种答案
        if (segId == SEG_COUNT) 
        {
            if (segStart == s.size()) 
            {
                string ipAddr;
                for (int i = 0; i < SEG_COUNT; ++i) 
                {
                    ipAddr += to_string(segments[i]);
                    if (i != SEG_COUNT - 1) 
                    {
                        ipAddr += ".";
                    }
                }
                ans.push_back(move(ipAddr));
            }
            return;
        }

        // 如果还没有找到 4 段 IP 地址就已经遍历完了字符串，那么提前回溯
        if (segStart == s.size()) 
        {
            return;
        }

        // 由于不能有前导零，如果当前数字为 0，那么这一段 IP 地址只能为 0
        if (s[segStart] == '0') 
        {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        // 一般情况，枚举每一种可能性并递归
        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); ++segEnd) 
        {
            addr = addr * 10 + (s[segEnd] - '0');
            if (addr > 0 && addr <= 255) 
            {
                segments[segId] = addr;
                dfs(s, segId + 1, segEnd + 1);
            } 
            else 
            {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) 
    {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }
};