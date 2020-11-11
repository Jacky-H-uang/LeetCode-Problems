// 实现 int sqrt(int x) 函数。
// 计算并返回 x 的平方根，其中 x 是非负整数。
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//
// 示例 1:
// 输入: 4
// 输出: 2
//
// 示例 2:
// 输入: 8
// 输出: 2
// 说明: 8 的平方根是 2.82842..., 
//      由于返回类型是整数，小数部分将被舍去。

#include<iostream>
#include<math.h>
using namespace std;


//整数平方根：
// 存在整数 a 满足 a^2 <= x <= (a + 1)^2 称 a 为 x 的 整数平方根。
// 从几何角度来看，整数平方根就是小于 xx 的最大正方形的边长。


//牛顿法
class Solution1
{
public:
    int mySqrt(int x) 
    {
        if(x<2)
        {
            return x;
        }
        double x1 = 6;
        double x2 = (x1+x/x1)/2.0;
        while(abs(x2-x1)>=1)                //收敛
        {
            x1 = x2;
            x2 = (x1+x/x1)/2.0;
        }
        return (int)x2;
    }
};



//二分查找法：   当 x >= 2 时，它的整数平方根一定小于 x/2 且大于 0，即 0 < a < x/2。
//              由于 a 一定是整数，此问题可以转换成在有序整数集中寻找一个特定值，因此可以使用二分查找。
class Solution2 {
public:
    int mySqrt(int x) 
    {
        if(x<2)
        {
            return x;
        }
        long num;
        int left = 2;
        int right = x/2;
        int mid;
        while(left<=right)
        {
            mid = (left+right)/2;
            num = (long)mid*mid;
            if(num>x)
            {
                right = mid-1;
            }
            else if (num < x)
            {
                left = mid+1;
            }
            else
            {
                return mid;
            }
        }
        return right;
    }
};