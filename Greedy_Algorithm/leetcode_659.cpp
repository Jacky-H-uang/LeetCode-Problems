//                                          659. 分割数组为连续子序列
//
// 给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，
// 其中每个子序列都由连续整数组成且长度至少为 3 。
//
// 如果可以完成上述分割，则返回 true ；否则，返回 false 。
//
//
// 示例 1：
// 输入: [1,2,3,3,4,5]
// 输出: True
// 解释:
// 你可以分割出这样两个连续子序列 : 
// 1, 2, 3
// 3, 4, 5
//
//
// 示例 2：
// 输入: [1,2,3,3,4,4,5,5]
// 输出: True
// 解释:
// 你可以分割出这样两个连续子序列 : 
// 1, 2, 3, 4, 5
// 3, 4, 5
//
//
// 示例 3：
// 输入: [1,2,3,4,4,5]
// 输出: False
//
//
// 提示：
// 输入的数组长度范围为 [1, 10000]

#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    // 贪心的选择：
    // 每次遍历三个数将其数量减一 ， 将以最后一个数结尾的数量 + 1
    // 然后再一个个遍历，遇到 0 的话就 continue 否则的话就观察能否与前一个接上
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (auto& x : nums)            mp1[x]++;

        for (auto& x : nums) {
            if(mp1[x] == 0)     continue;
            else if(mp1[x] > 0 && mp2[x-1] > 0) {
                mp1[x]--;
                mp2[x-1]--;
                mp2[x]++;
            }
            else if(mp1[x] > 0 && mp1[x+1] > 0 && mp1[x+2] > 0) {
                mp1[x]--;
                mp1[x+1]--;
                mp1[x+2]--;
                mp2[x+2]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};