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
   int reverse(long int x) {
    int  res=0;     //res��ʾ���

    while(x!=0)          
    {
        if(res>INT_MAX / 10) return 0;        //ע�⣺��ps
        if(res<INT_MIN / 10) return 0;        //�ж��Ƿ�Ҫ����Խ��
        res*=10;          
        res=res+x%10;   
        x=x/10;         
    }
    return res;
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