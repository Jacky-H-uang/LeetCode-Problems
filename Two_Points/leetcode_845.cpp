//                     845. Longest Mountain in Array
//
// Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
// B.length >= 3
// There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
// (Note that B could be any subarray of A, including the entire array A.)
// Given an array A of integers, return the length of the longest mountain. 
// Return 0 if there is no mountain.
//
//
// Example 1:
// Input: [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
//
//
// Example 2:
// Input: [2,2,2]
// Output: 0
// Explanation: There is no mountain.
//
//
// Note:
// 0 <= A.length <= 10000
// 0 <= A[i] <= 10000
//
//
// Follow up:
// Can you solve it using only one pass?
// Can you solve it in O(1) space?


#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    int longestMountain(vector<int>& A) {
        // 中心拓展法
        int n = A.size();
        int ans = 0;
        for(int i = 1; i < n-1; ++i)
        {
            if(A[i-1] < A[i] && A[i] > A[i+1])
            {
                int L = i-1;
                int R = i+1;
                while(L > 0 && A[L] > A[L-1])   L--;
                while(R < n-1 && A[R] > A[R+1])   R++;
                ans = max(ans , R-L+1);
            }
        }

        return ans;
    }
};