// 你有 k 个升序排列的整数数组。找到一个最小区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
// 我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。
//
//
// 示例 1:
// 输入:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
// 输出: [20,24]
// 解释: 
// 列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
// 列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
// 列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
//
//
// 注意:
// 给定的列表可能包含重复元素，所以在这里升序表示 >= 。
// 1 <= k <= 3500
// -105 <= 元素的值 <= 105
// 对于使用Java的用户，请注意传入类型已修改为List<List<Integer>>。重置代码模板后可以看到这项改动。


#include<bits/stdc++.h>
using namespace std;

// Hard

// 4    10      15      24      26
//
// 0    9       12      20
//
// 5    18      22      30
//
// 堆的解法：
// 让一个堆来存储每一行中的相比之下的最小的元素，先找到左边界，然后再找到右边界
//
// 时间复杂度：O(nklogk)
// 空间复杂度：O(k)
// 其中 k 是列表数量

class Solution {
public:
    // 重点在于如何找到矩阵中的左边界！！！（个人认为有点类似双指针的遍历）
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int rangeLeft = 0;                                              // 左边界（枚举区间的最小值）
        int rangeRight = INT_MAX;                                       // 右边界（比最小值大的最小值中的最大值---有点绕口）
        int size = nums.size();
        vector<int> next(size);                                         // 每行的元素个数 (相当于列数)

        auto cmp = [&](const int& u,const int& v){return nums[u][next[u]] > nums[v][next[v]];};

        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);          // deltype(cmp)     ---自动推断 cmp 为一个 bool 函数
        int minValue = 0;                                               // 当前维护的左边界
        int maxValue = INT_MIN;                                         // 当前维护的右边界

        for(int i = 0; i < size; ++i)
        {
            pq.emplace(i);                                              // emplace 优化的插入函数
            maxValue = max(maxValue,nums[i][0]);
        }

        while(true)
        {
            int row = pq.top();                                         // 取出当前行的索引
            pq.pop();
            minValue = nums[row][next[row]];
            
            if(maxValue - minValue < rangeRight - rangeLeft)
            {
                rangeLeft = minValue;
                rangeRight = maxValue;
            }

            if(next[row] == nums[row].size()-1)                         // 当这行元素遍历完的时候跳出循环
            {
                break;
            }

            ++next[row];                                                // 列往后枚举
            maxValue = max(maxValue,nums[row][next[row]]);              // 更新右边界的值
            pq.emplace(row);                                            // 重新插入让最小堆中的元素重新排序以便找到左边界
        }

        return {rangeLeft , rangeRight};
    }
};