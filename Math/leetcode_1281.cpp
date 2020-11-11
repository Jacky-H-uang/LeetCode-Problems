// ����һ������ n�������æ���㲢���ظ���������λ����֮�����롸��λ����֮�͡��Ĳ
//
// ʾ�� 1��
// ���룺n = 234
// �����15 
// ���ͣ�
// ��λ��֮�� = 2 * 3 * 4 = 24 
// ��λ��֮�� = 2 + 3 + 4 = 9 
// ��� = 24 - 9 = 15
//
// ʾ�� 2��
// ���룺n = 4421
// �����21
// ���ͣ� 
// ��λ��֮�� = 4 * 4 * 2 * 1 = 32 
// ��λ��֮�� = 4 + 4 + 2 + 1 = 11 
// ��� = 32 - 11 = 21
// 
// ��ʾ��
// 1 <= n <= 10^5
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        string str = to_string(n);
        int len = str.length();
        int MUL = 1;
        int SUM = 0;
        for(int i=len-1;i>=0;i--)
        {
            int temp = str[i]-'0';
            MUL *= temp;
            SUM += temp;
        }
        int result = MUL - SUM;
        return result;
    }
};

int main()
{
    int a = 4421;
    Solution s;
    int r = s.subtractProductAndSum(a);
    cout<<r<<endl;
    system("pause");
    return 0;
}
