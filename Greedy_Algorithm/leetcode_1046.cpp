// ��һ��ʯͷ��ÿ��ʯͷ������������������
// ÿһ�غϣ�����ѡ���������ص�ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x �� y���� x <= y��
// ��ô����Ŀ��ܽ�����£�
// ��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
// ��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y-x��
// ������ֻ��ʣ��һ��ʯͷ�����ش�ʯͷ�����������û��ʯͷʣ�£��ͷ��� 0��
// 
// ��ʾ��
// 1 <= stones.length <= 30
// 1 <= stones[i] <= 1000


//Easy
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        int len = stones.size();
        sort(stones.begin(),stones.end());
        while(len>0)
        {
            if(len == 1)
            {
                return stones[0];
            }
            if(stones[len-2] == stones[len-1])
            {
                stones.pop_back();
                stones.pop_back();
                len = len-2;
                continue;
            }
            if(stones[len-2] < stones[len-1])
            {
                int a = stones[len-1]-stones[len-2];
                stones.pop_back();
                stones.pop_back();
                stones.push_back(a);
                sort(stones.begin(),stones.end());
                len = len-1;
            }
        }
        return 0;
    }
};
int main()
{
    vector<int> a;
    for(int i=0;i<10;i++)
    {
        a.push_back(i);
    }
    Solution s;
    int r = s.lastStoneWeight(a);
    cout<<r<<endl;
    system("pause");
    return 0;
}