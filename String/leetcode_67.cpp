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

// 注意进位: 2 进 1
class Solution {
public:
	string addBinary(string a, string b)
	{
        if(a.size()<b.size())
		{
			swap(a,b);
		}
		int lenA = a.size();
		int lenB = b.size();
		if(b[0] == '0' && lenB == 1)
		{
			return a;
		}
		for(int i=lenA-lenB;i>0;i--)
		{
			b.insert(b.begin(),'0');
		}
		string result;
		int JW=0;
		for(int i=lenA-1;i>=0;i--)
		{
			int temp = a[i]-'0' + b[i] - '0';
			temp += JW;
			char t = temp +'0';
			if(temp == 2 || temp == 3)
			{
				temp = temp-2;
				char x = temp +'0';
				JW = 1;
				result.insert(result.begin(),x);
			}
			else
			{
				JW = 0;
				result.insert(result.begin(),t);
			}
		}
		if(result[0] == '0' || a[0] == b[0])
		{
			result.insert(result.begin(),'1');
		}
		return result;
	}
};


int main()
{
	string s1 = "1111";
	string s2 = "1111";
	Solution s;
	string r = s.addBinary(s1, s2);
	cout << r << endl;
    system("pause");
	return 0;
}