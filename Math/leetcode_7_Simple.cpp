// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//
// 示例1:
// 输入: 123
// 输出: 321
//
// 示例 2:
// 输入: -123
// 输出: -321
//
// 示例 3:
// 输入: 120
// 输出: 21
//
// 注意:
// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为[-2^31,2^31-1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
//Easy
class Solution {
public:
   int reverse(long int x) {
    int  res=0;     //res表示结果

    while(x!=0)          
    {
        if(res>INT_MAX / 10) return 0;        //注意：看ps
        if(res<INT_MIN / 10) return 0;        //判断是否将要发生越界
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