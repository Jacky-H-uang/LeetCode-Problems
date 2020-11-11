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
    int reverse(int x) 
    {
        long long flag = 1;
        if(x<0)
        {
            flag = -flag;
        }
        long long tt = flag*(long long)x;
        string temp = to_string(tt);
        long long len = temp.size();
        string tem = "";
        for(int i=len;i>0;i--)
        {
            tem += temp[i-1];
        }
        long long r = stoll(tem);
        if(r > INT32_MAX || flag*r == INT32_MIN)
        {
            return 0;
        }
        else
        {
            return flag*r;
        }
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