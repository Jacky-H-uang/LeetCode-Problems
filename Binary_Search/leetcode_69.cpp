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

//Easy

class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<1)
        {
            return 0;
        }
        int i=1;
        int result = 0;
        while(i*i<=x)
        {

            if(pow(i,2) > x)
            {
                break;
            }
            result = i;
            i++;
        }
        return result;
    }
};


int main()
{
    int a = 16;
    Solution s;
    int r = s.mySqrt(a);
    cout<<r<<endl;
    system("pause");
    return 0;
}