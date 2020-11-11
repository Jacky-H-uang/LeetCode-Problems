// 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
//
// 示例 1:
// 输入: 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1。
//
// 示例 2:
// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
//
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) 
    {
        if (n <= 3) 
        {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) 
        {
            return (int)pow(3, quotient);
        } 
        else if (remainder == 1) 
        {
            return (int)pow(3, quotient - 1) * 4;
        } 
        else 
        {
            return (int)pow(3, quotient) * 2;
        }
    }
};


int main()
{
    Solution s;
    cout<<s.integerBreak(11)<<endl;
    system("pause");
    return 0;
}