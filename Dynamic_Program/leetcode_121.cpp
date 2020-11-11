// ����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
// ��������ֻ�������һ�ʽ��ף������������һ֧��Ʊһ�Σ������һ���㷨�����������ܻ�ȡ���������
// ע�⣺�㲻���������Ʊǰ������Ʊ��
//
// ʾ�� 1:
// ����: [7,1,5,3,6,4]
// ���: 5
// ����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
//      ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
//
// ʾ�� 2:
// ����: [7,6,4,3,1]
// ���: 0
// ����: �����������, û�н������, �����������Ϊ 0��

#include<iostream>
#include<vector>
using namespace std;

//Easy

class Solution1 {
public:
    int maxProfit(vector<int>& prices) 
    {
        int len = (int)prices.size();
        if(len<=0)
        {
            return 0;
        }
        int mi = prices[0];
        int ma = 0;
        for(int i=1;i<len;i++)
        {
            ma = max(ma,prices[i]-mi);
            mi = min(mi,prices[i]);
        }
        return ma;
    }
};

//����ջ�Ľⷨ
//����ջ�������ǣ���O(n)��ʱ���֪����λ�����ߵ�һ��������(��С)������λ�á�
class Solution2 {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        vector<int> St;
        prices.emplace_back(-1);    // �ڱ�????
        for (int i = 0; i < prices.size(); ++ i)
        {
            while (!St.empty() && St.back() > prices[i])        // ά������ջ?
            {                 
                ans = max(ans, St.back() - St.front());         // ά�����ֵ
                St.pop_back();
            }
            St.emplace_back(prices[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    Solution2 s;
    int r = s.maxProfit(v);
    cout<<r<<endl;
    system("pause");
    return 0;
}