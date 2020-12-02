#include<bits/stdc++.h>
using namespace std;

// Hard

// 贪心的单调栈
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(1, 0);
        for (int x = 0; x <= m; ++x) {
            if (k - x > n || k - x < 0) continue;
            vector<int> sub1(sigleStack(nums1, x));
            vector<int> sub2(sigleStack(nums2, k - x));
            vector<int> cur(merge(sub1, sub2));
            if (compare(cur, 0, res, 0) > 0)    res = cur;
        }
        return res;
    }

    // 单调栈的模板罢了
    vector<int> sigleStack(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sta;
        for (int i = 0; i < n; ++i) {
            while (!sta.empty() && sta.back() < nums[i] && n - i > limit - sta.size()) {
                sta.pop_back();
            }
            if (sta.size() < limit)     sta.push_back(nums[i]);
        }
        return sta;
    }

    // 合并数组
    vector<int> merge(vector<int>& sub1, vector<int>& sub2) {
        vector<int> ret;
        int start1 = 0;
        int start2 = 0;
        while (start1 < sub1.size() && start2 < sub2.size()) {
            if (compare(sub1, start1, sub2, start2) > 0) ret.push_back(sub1[start1++]);
            else ret.push_back(sub2[start2++]);
        }
        while (start1 < sub1.size()) ret.push_back(sub1[start1++]);
        while (start2 < sub2.size()) ret.push_back(sub2[start2++]);
        return ret;
    }

    int compare(vector<int>& res1, int start1, vector<int>& res2, int start2) {
        int i = start1;
        int j = start2;
        for (; i < res1.size() && j < res2.size(); ++i, ++j) {
            int diff = res1[i] - res2[j];
            if (diff != 0)      return diff;
        }
        
        return (res1.size() - i) - (res2.size() - j);
    }
};