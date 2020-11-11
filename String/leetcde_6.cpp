// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
// 请你实现这个将字符串进行指定行数变换的函数：
// string convert(string s, int numRows);
//
// 示例 1:
// 输入: s = "LEETCODEISHIRING", numRows = 3
// 输出: "LCIRETOESIIGEDHN"
//
// 示例 2:
// 输入: s = "LEETCODEISHIRING", numRows = 4
// 输出: "LDREOEIIECIHNTSG"
// 解释:

// L     D     R
// E   O E   I I
// E C   I H   N
// T     S     G

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//Medium

class Solution {
public:
	string convert(string s, int numRows)
	{
        int len = s.size();
        int flag = 0 ;
        if(numRows == 1)
        {
            return s;
        }
        vector<string> v(numRows);
        int i = 0 ;
        while(i<len)
        {
            if(flag < numRows && s[i])
            {
                v[flag].push_back(s[i]);
                flag++;
            }
            else
            {           
                while(flag-2 && s[i])
                {
                    v[flag-2].push_back(s[i]);
                    i++;
                    flag--;
                }
                flag = 0;
                continue;
            }
            i++;
        }
        string result = "";
        for(int i=0;i<v.size();i++)
        {
            result += v[i];
        }
        return result;
	}
};


int main()
{
    string a = "ABCDE";
    Solution s;
    string r = s.convert(a,4);
    cout<<r<<endl;
    system("pause");
    return 0;
}