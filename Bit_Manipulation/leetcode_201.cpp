//           201. 数字范围按位与
//
// 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
//
//
// 示例 1: 
// 输入: [5,7]
// 输出: 4
//
//
// 示例 2:
// 输入: [0,1]
// 输出: 0


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 1;
        while(i <= 32)
        {
            // 用 undigested int 可以取到 2^31
            unsigned int temp = (1<<i);
            temp -= 1;
            if(temp < m)
            {
                i++;
            }
            else if(m <= temp && temp < n)
            {
                return 0;
            }
            else
            {
                break;
            }
        }

        int ans = m;

        for(unsigned int j = m;j <=n; ++j)
        {
            ans &= j;
        }
        return ans;
    }
};