//����һ����ʾ�����Ӽ�������ʽ���ַ���������Ҫ����һ���ַ�����ʽ�ļ�������
//������Ӧ���ǲ���Լ�ֵķ���������������?������ս����һ������������ 2������Ҫ����ת���ɷ�����ʽ�����ĸΪ 1������������������, 2 Ӧ�ñ�ת��Ϊ?2/1��
//
//ʾ��1:
//����:"-1/2+1/2"
//���: "0/1"
//
//ʾ�� 2:
//����:"-1/2+1/2+1/3"
//���: "1/3"
//
//ʾ�� 3:
//����:"1/3-1/2"
//���: "-1/6"
//
//ʾ�� 4:
//����:"5/3+1/3"
//���: "2/1"
//
//˵��:
//���������ַ���ֻ����'0' ��'9'�����֣��Լ�'/', '+' ��'-'
//��������������ʽ��Ϊ������/��ĸ���������ĵ�һ��������������ķ�������������'+'�ᱻʡ�Ե���
//����ֻ�����Ϸ�����������ÿ�������ķ������ĸ�ķ�Χ�� [1,10]�������ĸ��1����ζ���������ʵ������һ��������
//����ķ���������Χ�� [1,10]��
//���ս���ķ������ĸ��֤�� 32 λ������Χ�ڵ���Ч������
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