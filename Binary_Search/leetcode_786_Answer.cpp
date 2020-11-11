// 786. 第 K 个最小的素数分数
// 一个已排序好的表 A，其包含 1 和其他一些素数.  当列表中的每一个 p<q 时，我们可以构造一个分数 p/q 。
// 那么第 k 个最小的分数是多少呢? 以整数数组的形式返回你的答案, 这里 answer[0] = p 且 answer[1] = q.

// 示例:
// 输入: A = [1, 2, 3, 5], K = 3
// 输出: [2, 5]
// 解释:
// 已构造好的分数,排序后如下所示:
// 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
// 很明显第三个最小的分数是 2/5.

// 输入: A = [1, 7], K = 1
// 输出: [1, 7]

// 注意:
// A 长度的取值范围在 2 ~ 2000.
// 每个A[i] 的值在 1 ~ 30000.
// K 取值范围为 1 ~ A.length*(A.length-1)/2。





//Difficult
// 1.二分查找         思路：使用二分查找找出一个 x，使得小于 x 的分数恰好有 K 个，并且记录其中最大的一个分数。
//                        我们的二分搜索与其他的二分搜索方法类似：初始有区间 [lo, hi]，中心点 mi = (lo + hi) / 2.0。
//                        如果小于 mi 的分数数量小于 K，更新区间为 [mi, hi]，否则更新为 [lo, mi]。更多关于二分搜索的内容，请访问 LeetCode 探索这里。
//                        under(x) 函数有两个目的：返回小于 x 的分数数量以及小于 x 的最大分数。
//                        在 under(x) 函数中使用滑动窗口的方法：对于每个 primes[j]，找出最大的 i 使得 primes[i] / primes[j] < x。随着 j （和 primes[j]）的增加， i 也会随之增加。

//2.堆记录法         思路: 使用一个堆记录所有以 primes[j] 为分母且未被弹出的最小分数。依次从堆中弹出 K-1 个元素，此时堆顶的分数就是结果。
#include<iostream>
#include<vector>
using namespace std;
class Solution1{            //二分查找       
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