//                                          861. 翻转矩阵后的得分
//
// 有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
// 移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
// 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
// 返回尽可能高的分数。
//
//
// 示例：
// 输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// 输出：39
// 解释：
// 转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//
//
// 提示：
// 1 <= A.length <= 20
// 1 <= A[0].length <= 20
// A[i][j] 是 0 或 1

#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        int ans = 0;

        // 遍历行
        for(int i = 0; i < m; ++i) {
            if(A[i][0] == 1)    continue;
            else {
                for(int j = 0; j < A[i].size(); ++j){
                    if(A[i][j] == 0)    A[i][j] = 1;
                    else                A[i][j] = 0;
                }
            }
        }

        // 遍历列
        for(int i = 0; i < n; ++i) {
            int cnt0 = 0;
            int cnt1 = 1;
            for(int j = 0; j < m; ++j) {
                if(A[j][i] == 0)    cnt0++;
                else                cnt1++;
            }
            if(cnt0 >= cnt1) {
                for(int j = 0; j < m; ++j) {
                    if(A[j][i] == 0)    A[j][i] = 1;
                    else                A[j][i] = 0;
                }
            }
        }


        // 最后二进制算结果
        for(int i = 0; i < m; ++i) {
            int sum = 0;
            int k = n;
            for(int j = 0; j < n; ++j) {
                if(A[i][j] == 1)  sum += 1<<(k-1);
                k--;
            }
            ans += sum;
        }

        return ans;
    }
};