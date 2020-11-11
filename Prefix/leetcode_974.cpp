//                      974. Subarray Sums Divisible by K
// Medium
//
// Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
//
//
// Example 1:
// Input: A = [4,5,0,-2,-3,1], K = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by K = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//
//
// Note:
// 1 <= A.length <= 30000
// -10000 <= A[i] <= 10000
// 2 <= K <= 10000





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int,int> ht;
        int sum = 0;
        int ans = 0;
        A.insert(A.begin(),0);
        for(auto& a : A) {
            sum = (sum + a) % K;
            ht[(sum + K) % K]++;
        }

        for(auto& [x,y] : ht) {
            ans += (y * (y - 1)) / 2;
        }

        return ans;
    }
};

//同余定理：P[j]-P[i-1] 连续的子数和
//         (P[j]-P[i-1]) mod K == 0
//         则P[j] mod K == P[i] mod K
//所以此题可以使用它的逆定理