// 786. 第 K 个最小的素数分数
// 一个已排序好的表 A，其包含 1 和其他一些素数.? 当列表中的每一个 p<q 时，我们可以构造一个分数 p/q 。
// 那么第 k 个最小的分数是多少呢? 以整数数组的形式返回你的答案, 这里 answer[0] = p 且 answer[1] = q.
//
// 示例:
// 输入: A = [1, 2, 3, 5], K = 3
// 输出: [2, 5]
// 解释:
// 已构造好的分数,排序后如下所示:
// 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
// 很明显第三个最小的分数是 2/5.
//
// 输入: A = [1, 7], K = 1
// 输出: [1, 7]
//
// 注意:
// A 长度的取值范围在 2 — 2000.
// 每个A[i] 的值在 1 —30000.
// K 取值范围为 1—A.length*(A.length-1)/2。

//Difficult
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


// 超时 TimeExceeded
class Solution {
public:
    struct cmp
    {   
        bool operator()(vector<int> x,vector<int> y)
        {
            double a = 1.0*x[0]/x[1]*1.0;
            double b = 1.0*y[0]/y[1]*1.0;
            return a > b;
        }
    };
    
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) 
    {
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        int len = A.size();
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                int a = A[i];
                int b = A[j];
                if((double)a/(double)b >1)
                {

                }
                vector<int> temp;
                temp.push_back(a);
                temp.push_back(b);
                pq.push(temp);
            }
        }
        vector<int> result;
        while(K)
        {
            result = pq.top();
            pq.pop();
            K--;
        }
        return result;
    }
};

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(8);
    //A.push_back(3);
    //A.push_back(7);
    int K = 1;
    Solution s;
    vector<int> r = s.kthSmallestPrimeFraction(A,K);
    cout<<r[0]<<" "<<r[1]<<endl;
    system("pause");
    return 0;
}