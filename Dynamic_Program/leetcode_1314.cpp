// ����һ�� m * n �ľ��� mat ��һ������ K �����㷵��һ������ answer������ÿ�� answer[i][j] ��������������������Ԫ�� mat[r][c] �ĺ�:
// i - K <= r <= i + K, j - K <= c <= j + K
// (r, c) �ھ����ڡ�
// 
// ʾ�� 1��
// ���룺mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
// �����[[12,21,16],[27,45,33],[24,39,28]]
//
// ʾ�� 2��
// ���룺mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
// �����[[45,45,45],[45,45,45],[45,45,45]]
// 
// ��ʾ��
// m == mat.length
// n == mat[i].length
// 1 <= m, n, K <= 100
// 1 <= mat[i][j] <= 100

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //����ֵ�� abs() ����
    //r-i <= |K|
    //c-j <= |K|
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
    {
        int m = mat.size();        // j�ķ�Χ
        vector<vector<int>> answer(m);
        for(int j=0;j<m;j++)
        {
            int n = mat[j].size();
            for(int i=0;i<n;i++)
            {
                int temp = 0;
                vector<int> r;
                vector<int> c;
                for(int q=0;q<m;q++)
                {
                    if(q>=j-K && q<=j+K)
                    {
                        r.push_back(q);
                    }
                }
                for(int p=0;p<n;p++)     
                {
                    if(p>=i-K && p<=i+K)
                    {
                        c.push_back(p);
                    }
                }
                int x = r.size();       //��
                int y = c.size();       //��
                for(int ii = 0;ii<x;ii++)
                {
                    for(int jj = 0;jj<y;jj++)
                    {
                        temp += mat[r[ii]][c[jj]];
                    }
                }
                answer[j].push_back(temp);
            }
        }
        return answer;
    }
};


int main()
{
    vector<vector<int>> sample(3);
    sample[0].push_back(1);
    sample[0].push_back(2);
    sample[0].push_back(3);
    sample[1].push_back(4);
    sample[1].push_back(5);
    sample[1].push_back(6);
    sample[2].push_back(7);
    sample[2].push_back(8);
    sample[2].push_back(9);
    Solution s;
    vector<vector<int>> rr = s.matrixBlockSum(sample,1);
    for(int i=0;i<rr.size();i++)
    {
        for(int j=0;j<rr[i].size();j++)
        {
            cout<<rr[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}