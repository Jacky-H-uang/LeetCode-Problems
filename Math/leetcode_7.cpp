// ����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��
//
// ʾ��1:
// ����: 123
// ���: 321
//
// ʾ�� 2:
// ����: -123
// ���: -321
//
// ʾ�� 3:
// ����: 120
// ���: 21
//
// ע��:
// �������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ[-2^31,2^31-1]�������������裬�����ת�����������ô�ͷ��� 0��

#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
//Easy
class Solution {
public:
    int reverse(int x) 
    {
        long long flag = 1;
        if(x<0)
        {
            flag = -flag;
        }
        long long tt = flag*(long long)x;
        string temp = to_string(tt);
        long long len = temp.size();
        string tem = "";
        for(int i=len;i>0;i--)
        {
            tem += temp[i-1];
        }
        long long r = stoll(tem);
        if(r > INT32_MAX || flag*r == INT32_MIN)
        {
            return 0;
        }
        else
        {
            return flag*r;
        }
    }
};

int main()
{
    int a = 123;
    Solution s;
    int r = s.reverse(a);
    cout<<r<<endl;
    system("pause");
    return 0;
}