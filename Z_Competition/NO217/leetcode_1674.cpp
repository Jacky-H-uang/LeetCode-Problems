#include<bits/stdc++.h>
using namespace std;

// Medium


// 当遇到要对一个连续的区域做同样的操作的时候可以使用差分数组
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        
        // 差分数组, diff[0...x] 的和表示最终互补的数字和为 x，需要的操作数
        // 因为差分数组的计算需要更新 r + 1，所以数组的总大小在 limit * 2 + 1 的基础上再 + 1
        vector<int> diff(limit * 2 + 2, 0);

        int n = nums.size();
        for(int i = 0; i < n / 2; ++i) {
            int A = nums[i], B = nums[n - 1 - i];

            // [2, 2 * limit] 范围 + 2
            int l = 2;
            int r = 2 * limit;
            diff[l] += 2;
            diff[r + 1] -= 2;

            // [1 + min(A, B), limit + max(A, B)] 范围 -1
            l = 1 + min(A, B);
            r = limit + max(A, B);
            diff[l] += -1;
            diff[r + 1] -= -1;

            // [A + B] 再 -1    
            l = A + B;
            r = A + B;
            diff[l] += -1;
            diff[r + 1] -= -1;
        }

        // 依次求和，得到 最终互补的数字和 i 的时候，需要的操作数 sum
        // 取最小值
        int res = n, sum = 0;
        for(int i = 2; i <= 2 * limit; i ++) {
            sum += diff[i];
            if(sum < res) res = sum;
        }
        return res;
    }
};