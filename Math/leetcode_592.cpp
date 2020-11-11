//给定一个表示分数加减运算表达式的字符串，你需要返回一个字符串形式的计算结果。
//这个结果应该是不可约分的分数，即最简分数。?如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为?2/1。
//
//示例1:
//输入:"-1/2+1/2"
//输出: "0/1"
//
//示例 2:
//输入:"-1/2+1/2+1/3"
//输出: "1/3"
//
//示例 3:
//输入:"1/3-1/2"
//输出: "-1/6"
//
//示例 4:
//输入:"5/3+1/3"
//输出: "2/1"
//
//说明:
//输入和输出字符串只包含'0' 到'9'的数字，以及'/', '+' 和'-'
//输入和输出分数格式均为±分子/分母。如果输入的第一个分数或者输出的分数是正数，则'+'会被省略掉。
//输入只包含合法的最简分数，每个分数的分子与分母的范围是 [1,10]。如果分母是1，意味着这个分数实际上是一个整数。
//输入的分数个数范围是 [1,10]。
//最终结果的分子与分母保证是 32 位整数范围内的有效整数。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
	struct FenShu
	{
		int FenZ;
		int FenM;
	};
	string fractionAddition(string expression)
	{
		vector<int> v;
		int len = expression.length();
		for (int i = 0; i < len; i++)
		{
			if (expression[i] == '+' || expression[i] == '/')
			{
				continue;
			}
			if (expression[i] == '-')
			{
				int sign = -1;
				v.push_back(sign);
				continue;
			}
            int tem = i+1;
            if(expression[tem] == '0')
            {
                v.push_back(10);
                i++;
                continue;
            }
            int temp = expression[i] - '0';
		    v.push_back(temp);
		}
		int vlen = v.size();
		int l = 0;
		int count = 0;
		vector < FenShu > F;
		FenShu ttt;
		while (l < vlen)
		{
			if (v[l] == -1)
			{
				int p1 = l + 1;
				int p2 = l + 2;
				ttt.FenZ = -v[p1];
				ttt.FenM = v[l + 2];
				l = l + 3;
				F.push_back(ttt);
				continue;
			}
			else
			{
				ttt.FenZ = v[l];
				ttt.FenM = v[l + 1];
				F.push_back(ttt);
				l = l + 2;
			}
		}
		FenShu result = Caculate(F);
		string m1 = "";
		string m2;
		string m3;
		if (result.FenZ < 0)
		{
			result.FenZ = -result.FenZ;
			m1 = "-";
			m2 = to_string(result.FenZ);
		}
        if(result.FenZ==0)
        {
            m2 = "0";
            m3 = "1";
            return m1+m2+"/"+m3;
        }
        FenShu rrr = YueFen(result);
		m2 = to_string(rrr.FenZ);
		m3 = to_string(rrr.FenM);
		return m1 + m2 +"/" + m3;
	}
	FenShu Caculate(vector<FenShu> s)
	{
		FenShu temp;
		temp.FenZ = 0;
		temp.FenM = 1;
		vector<FenShu>::iterator it = s.begin();
		for(;it!=s.end();it++)
		{
			int x1 = temp.FenZ * (*it).FenM;
			int x2 = temp.FenM * (*it).FenZ;
			int x3 = x1 + x2;
			int y = temp.FenM * (*it).FenM;
			temp.FenZ = x3;
			temp.FenM = y;
		}
		return temp;
	}
    FenShu YueFen(FenShu x)
    {
        int m1 = x.FenZ;
        int m2 = x.FenM;
        int mi = min(m1,m2); 
        for(int i=2;i<=mi;i++)
        {
            if(m1%i ==0 && m2%i == 0)
            {
                m1 =m1 / i;
                m2 =m2 / i;
                i--;
            }
        }
        FenShu F;
        F.FenZ = m1;
        F.FenM = m2;
        return F;
    }
};

int main()
{
	string x = "-5/2+10/3+7/9";
	Solution s;
	string r = s.fractionAddition(x);
	cout << r << endl;
    system("pause");
	return 0;
}