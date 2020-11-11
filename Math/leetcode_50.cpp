// Implement pow(x, n), which calculates x raised to the power n (x^n).
//
// Example 1:
// Input: 2.00000, 10
// Output: 1024.00000
//
// Example 2:
// Input: 2.10000, 3
// Output: 9.26100
//
// Example 3:
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
//
// Note:
// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]



#include<iostream>
#include<math.h>
using namespace std;

//Medium

//快速幂的 迭代法
//时间复杂度O(lgn)
class Solution1 {                                
public:
    double myPow(double x, int n) 
    {
        double result = 1.0;
        for(int i=n;i!=0;i=i/2)                 //无论如何都会回溯到1
        {
            if(i%2 != 0)
            {
                result *= x;
            }
            x *= x;
        }
        return n<0? 1/result:result;
    }
};



//快速幂 的递归
//先递归地计算出 y = x^⌊n/2⌋ 
//时间复杂度O(lgn)
class Solution2 {
public:
    double func(double x,int n)
    {
        if(n==0)
        {
            return 1.0;
        }
        double half = func(x,n/2);
        if(n%2 != 0)
        {
            //eg :  从 x^32 --> x^63  一定是两个 half 与 一个 x 。此时是为 x^32 * x^32 * x
            return half*half*x;                
        }
        else
        {
            return half*half;
        }
    }
    double myPow(double x,int n)
    {
        long long N = abs(n);
        double result = func(x,N);
        return n<0? 1.0/result:result;
    }
};



int main()
{
    Solution1 s;
    cout<<s.myPow(1.01,2)<<endl;
    system("pause");
    return 0;
}