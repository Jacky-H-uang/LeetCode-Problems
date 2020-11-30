#include<bits/stdc++.h>
using namespace std;


// [2,4,3,3,5,4,9,6]
// 4

class Solution {
public:
    // 相当于排最小的 k 位数字
    // 利用单调栈的性质
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> stk;
        stk.push(-1);
        vector<int> ans;
        ans.resize(k);

        for(int i = 0; i < n; ++i) {
            while(nums[i] < stk.top() && k - stk.size() + 1 < n-i) {
                stk.pop();
            }
            if(stk.size() < k+1) {
                stk.push(nums[i]);
            }
        }

        while(k > 0) {
            ans[--k] = stk.top();
            stk.pop();
        }

        return ans;
    }
};