// 786. �� K ����С����������
// һ��������õı� A������� 1 ������һЩ����.  ���б��е�ÿһ�� p<q ʱ�����ǿ��Թ���һ������ p/q ��
// ��ô�� k ����С�ķ����Ƕ�����? �������������ʽ������Ĵ�, ���� answer[0] = p �� answer[1] = q.

// ʾ��:
// ����: A = [1, 2, 3, 5], K = 3
// ���: [2, 5]
// ����:
// �ѹ���õķ���,�����������ʾ:
// 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
// �����Ե�������С�ķ����� 2/5.

// ����: A = [1, 7], K = 1
// ���: [1, 7]

// ע��:
// A ���ȵ�ȡֵ��Χ�� 2 ~ 2000.
// ÿ��A[i] ��ֵ�� 1 ~ 30000.
// K ȡֵ��ΧΪ 1 ~ A.length*(A.length-1)/2��





//Difficult
// 1.���ֲ���         ˼·��ʹ�ö��ֲ����ҳ�һ�� x��ʹ��С�� x �ķ���ǡ���� K �������Ҽ�¼��������һ��������
//                        ���ǵĶ��������������Ķ��������������ƣ���ʼ������ [lo, hi]�����ĵ� mi = (lo + hi) / 2.0��
//                        ���С�� mi �ķ�������С�� K����������Ϊ [mi, hi]���������Ϊ [lo, mi]��������ڶ������������ݣ������ LeetCode ̽�����
//                        under(x) ����������Ŀ�ģ�����С�� x �ķ��������Լ�С�� x ����������
//                        �� under(x) ������ʹ�û������ڵķ���������ÿ�� primes[j]���ҳ����� i ʹ�� primes[i] / primes[j] < x������ j ���� primes[j]�������ӣ� i Ҳ����֮���ӡ�

//2.�Ѽ�¼��         ˼·: ʹ��һ���Ѽ�¼������ primes[j] Ϊ��ĸ��δ����������С���������δӶ��е��� K-1 ��Ԫ�أ���ʱ�Ѷ��ķ������ǽ����
#include<iostream>
#include<vector>
using namespace std;
class Solution1{            //���ֲ���       
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) 
    {
        double left = 0, right = 1.0, mid;
        int p = 0;
        int q = 1;
        int Asize = A.size();
        int count; 
        while (true) 
        {
            double mid = (left + right) / 2.0;
            count = 0; 
            p = 0;
            for (int i = 0, j = i+1; i < Asize; ++i) 
            {
                while (j < Asize && mid < (double)A[i]/(double)A[j]  )
                {
                    ++j;
                }
                count += Asize - j;
                if (j < Asize && (double)p/(double)q < (double)A[i]/(double)A[j]) 
                {
                    p = A[i];
                    q = A[j];
                }
            }
            if (count == K) 
            {
                return {p, q};
            }
            else if (count < K)
            {
                left = mid;
            }
            else                
            {
                right = mid;
            }
        }
    }
};