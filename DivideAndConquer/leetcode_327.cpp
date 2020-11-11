//                              327. Count of Range Sum
//
// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
//
// Note:
// A naive algorithm of O(n2) is trivial. You MUST do better than that.
//
// Example:
// Input: nums = [-2,5,-1], lower = -2, upper = 2,
// Output: 3 
// Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
//
//
// Constraints:
// 0 <= nums.length <= 10^4


#include<bits/stdc++.h>
using namespace std;
#define LL long long


// Hard
// T(n) = 2T(n/2) + O(n)        (经典分治成功)
class Solution {
public:
    int lower;
    int upper;
    // 计算区间和
    int calc(int i,int j,vector<int>& nums) {
        int sum = 0;
        for(int k = i; k < j; ++k)      sum += nums[k];
        return sum;
    }

    int divide(vector<LL>& prefix,int L,int R) 
    {
        if(L == R)      return 0;

        else
        {
            int mid = (L+R)>>1;
            int r1 = divide(prefix,L,mid);
            int r2 = divide(prefix,mid+1,R);
            int res = r1 + r2;

            int i = L;
            int l = mid + 1;
            int r = mid + 1;
            while(i <= mid)
            {
                while(l <= R && prefix[l] - prefix[i] < lower)      l++;
                while(r <= R && prefix[r] - prefix[i] <= upper)     r++;
                res += (r-l);
                ++i;
            }

            // merge 数组       (归并排序的思路)
            vector<int> aux(R-L+1);
            int p1 = L;
            int p2 = mid+1;
            int p = 0;
            while(p1 <= mid || p2 <= R) 
            {
                if(p1 > mid)            aux[p++] = prefix[p2++];
                else if(p2 > R)         aux[p++] = prefix[p1++];
                else
                {
                    if(prefix[p1] < prefix[p2])     aux[p++] = prefix[p1++];
                    else                            aux[p++] = prefix[p2++];
                }
            }
            for(int i = 0; i < aux.size(); ++i)     prefix[i+L] = aux[i];

            return res;
        }
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        this->lower = lower;
        this->upper = upper;

        // 前缀和的预处理
        vector<LL> prefix = {0};
        LL sum = 0;
        for(auto& x : nums)
        {
            sum += x;
            prefix.push_back(sum);
        }

        return divide(prefix,0,prefix.size()-1);
    }
};