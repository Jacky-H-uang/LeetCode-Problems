//                                      4. 寻找两个正序数组的中位数
//
// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//
//
// 示例 1：
// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2
//
// 示例 2：
// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
//
// 示例 3：
// 输入：nums1 = [0,0], nums2 = [0,0]
// 输出：0.00000
//
// 示例 4：
// 输入：nums1 = [], nums2 = [1]
// 输出：1.00000
//
// 示例 5：
// 输入：nums1 = [2], nums2 = []
// 输出：2.00000
//
//
// 提示：
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106
//
//
// 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？


#include<bits/stdc++.h>
using namespace std;

// 优先队列
class Solution {
public:
    struct cmp
    {
        bool operator()(int x,int y)
        {
            return x > y;
        }
    };

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        priority_queue<int,vector<int>,cmp> pqueue;
        for(auto i:nums1)       pqueue.push(i);

        for(auto j:nums2)       pqueue.push(j);

        int SIZE = pqueue.size();
        double result = 0.0;
        if(SIZE % 2==0) {
            int t1 = SIZE/2;
            int t2 = t1 + 1;
            for(int i=1;i<t1;i++)       pqueue.pop();
            int temp = pqueue.top();
            pqueue.pop();
            result = ((double)temp + (double)pqueue.top())/2.0;
        }
        else {
            int t1 = SIZE/2+1;
            for(int i=1;i<t1;i++)       pqueue.pop();
            double r1 = pqueue.top();
            result = r1/1.0;
        }
        return result;
    }
};