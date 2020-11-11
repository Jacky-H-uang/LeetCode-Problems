// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
// 示例 1:
// 输入: num1 = "2", num2 = "3"
// 输出: "6"
//
// 示例 2:
// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
//
//
// 说明：
// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。




#include<bits/stdc++.h>
using namespace std;

// Medium




// 由于乘法是相乘之后按位数来进行相加的
// 所以此题可以先按位数，把属于相同位的乘积相加存储到一个数组里面
// 之后问题就转换成了加法问题，其中要注意进位就可以了
class Solution {
public:
    string multiply(string num1, string num2) 
    {
        // 有 0 相乘的时候就直接返回 0 就可以了
        if(num1 == "0" || num2 == "0")
        {
            return "0"; 
        }

        string ans = "";
        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> store(len1+len2);           // 存储每一级相乘后相加的结果

        for(int i = len1-1; i >= 0; --i)
        {
            int x1 = num1[i]-'0';
            for(int j = len2-1; j >= 0; --j)
            {
                int x2 = num2[j]-'0';

                int multi = x1 * x2;            // 计算乘积

                store[i+j+1] += multi;          // 将属于同一级的乘法结果加起来
            }
        }


        // 处理加法
        int carry = 0;
        for(int i = len1+len2-1; i > 0; --i)
        {
            int temp = store[i] + carry;
            ans += to_string(temp%10);
            carry = temp / 10;
        }

        // 处理多余的进位
        if(carry != 0)
        {
            ans += to_string(carry);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};