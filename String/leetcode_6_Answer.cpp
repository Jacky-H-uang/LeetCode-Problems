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

class Solution1 {
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1) return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for (char c : s) 
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) 
            {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};



// 方法二：按行访问
// 思路:
// 按照与逐行读取 Z 字形图案相同的顺序访问字符串。
//
// 算法:
// 首先访问 行 0 中的所有字符，接着访问 行 1，然后 行 2，依此类推...
// 对于所有整数 k，

// 行 0 中的字符位于索引 k(2⋅numRows−2) 处;
// 行 numRows−1 中的字符位于索引 k(2⋅numRows−2)+numRows−1 处;
// 内部的行 i 中的字符位于索引 k(2⋅numRows−2)+i 以及 (k+1)(2⋅numRows−2)−i 处;

class Solution2 {
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1) return s;
        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) 
        {
            for (int j = 0; j + i < n; j += cycleLen) 
            {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    {
                        ret += s[j + cycleLen - i];
                    }
            }
        }
        return ret;
    }
};
