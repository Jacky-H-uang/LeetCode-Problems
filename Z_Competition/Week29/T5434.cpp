// 5434. 删掉一个元素以后全为 1 的最长子数组
//
// 给你一个二进制数组 nums ，你需要从中删掉一个元素。
// 请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。
// 如果不存在这样的子数组，请返回 0 。
//
//
// 示例 1：
// 输入：nums = [1,1,0,1]
// 输出：3
// 解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
//
// 示例 2：
// 输入：nums = [0,1,1,1,0,1,1,0,1]
// 输出：5
// 解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。
//
// 示例 3：
// 输入：nums = [1,1,1]
// 输出：2
// 解释：你必须要删除一个元素。
//
// 示例 4：
// 输入：nums = [1,1,0,0,1,1,1,0,1]
// 输出：4
//
// 示例 5：
// 输入：nums = [0,0,0]
// 输出：0
//
// 提示：
// 1 <= nums.length <= 10^5
// nums[i] 要么是 0 要么是 1 。


#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

// Medium

class Solution {
public:
    // 中心扩展算法
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) 
        {
            sum += a[i];
        }
        if (sum == n) 
        {
            return n-1;
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 1) 
            {
                continue;
            }
            int L = i, R = i;
            while (L-1 >= 0 && a[L-1] == 1) 
            {
                -- L;
            }
            while (R+1 < n && a[R+1] == 1) 
            {
                ++ R;
            }
            res = max(res, R-L);
        }
        return res;
    }
};