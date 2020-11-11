// 给你两个二进制字符串，返回它们的和（用二进制表示）。
// 输入为 非空 字符串且只包含数字 1 和 0。
//
// 示例 1:
// 输入: a = "11", b = "1"
// 输出: "100"
//
// 示例 2:
// 输入: a = "1010", b = "1011"
// 输出: "10101"
//
// 提示：
// 每个字符串仅由字符 '0' 或 '1' 组成。
// 1 <= a.length, b.length <= 10^4
// 字符串如果不是 "0" ，就都不含前导零。

#include<iostream>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<cstring>
using namespace std;

//Easy
class Solution {
public:
	string addBinary(string a, string b)
	{
        int asize = a.size(), bsize = b.size();
		while (asize > bsize)
		{
			b = '0' + b;
			bsize++;
		}
		while (asize < bsize)
		{
			a = '0' + a;
			asize++;
		}
		int carry = 0;
		for (int i = asize - 1; i >= 0; i--)
		{
			int sum = a[i] - '0' + b[i] - '0' + carry;
			a[i] = (sum) % 2+'0';
			carry = sum / 2;
		}
		if (carry > 0)
			a = '1' + a;
		return a;
	}
};