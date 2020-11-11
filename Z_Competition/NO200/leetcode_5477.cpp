// 给你一个 n x n 的二进制网格 grid，每一次操作中，你可以选择网格的 相邻两行 进行交换。
// 一个符合要求的网格需要满足主对角线以上的格子全部都是 0 。
// 请你返回使网格满足要求的最少操作次数，如果无法使网格符合要求，请你返回 -1 。
// 主对角线指的是从 (1, 1) 到 (n, n) 的这些格子。
//
//
//
// 示例 1：
// 输入：grid = [[0,0,1],[1,1,0],[1,0,0]]
// 输出：3
//
// 示例 2：
// 输入：grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
// 输出：-1
// 解释：所有行都是一样的，交换相邻行无法使网格符合要求。
//
// 示例 3：
// 输入：grid = [[1,0,0],[1,1,0],[1,1,1]]
// 输出：0
// 
//
// 提示：
// n == grid.length
// n == grid[i].length
// 1 <= n <= 200
// grid[i][j] 要么是 0 要么是 1 。

#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (grid[i][j] == 0) 
                {
                    // 从后往前记录 0 的个数
                    ++a[i];                         
                }
                else 
                {
                    break;
                }
            }
        }

        int rev = 0;

        for (int i = 0; i < n; ++i) 
        {
            if (a[i] < n - i - 1)
            {
                // 没有相匹配的零的话设为 false
                bool flag = false;              

                for (int j = i + 1; j < n; ++j) 
                {
                    if (a[j] >= n - i - 1) 
                    {
                        // 计算交换的次数
                        rev += j - i;
                        
                        // 记录符合当前零个数的 a[i]
                        int temp = a[j];

                        // 从后往前交换
                        for (int k = j; k > i; --k) 
                        {
                            a[k] = a[k - 1];
                        }


                        a[i] = temp;
                        
                        // 找到符合要求的 0 的个数，将 flag 设置为 true
                        flag = true;
                        break;
                    }
                }
                if (!flag) 
                {
                    return -1;
                }
            }
        }
        return rev;
    }
};