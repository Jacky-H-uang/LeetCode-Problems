// 给定一个整数 n，返回 n! 结果尾数中零的数量。
//
// 示例 1:
// 输入: 3
// 输出: 0
// 解释: 3! = 6, 尾数中没有零。
//
// 示例 2:
// 输入: 5
// 输出: 1
// 解释: 5! = 120, 尾数中有 1 个零.
//
// 说明: 你算法的时间复杂度应为 O(log n) 。


#include<iostream>
using namespace std;

//Easy


/**
 * Ans = N/5 + N/(5^2) + N/(5^3) + ...
 * Ans = N/5 + N/(5^2) + N/(5^3) + ... = ((N / 5) / 5) / 5 /...
 */

class Solution {
public:
    int trailingZeroes(int n) 
    {
        int r = 0;
        while(n)
        {
            int temp = n/5;
            r += temp;
            n = n/5;
        }
        return r;
    }
};



int main()
{
    Solution s;
    int r = s.trailingZeroes(200);
    cout<<r<<endl;
    system("pause");
    return 0;
}