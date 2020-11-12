//                              922. Sort Array By Parity II
// Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
// Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
// You may return any answer array that satisfies this condition.
//
//
// Example 1:
// Input: [4,2,5,7]
// Output: [4,5,2,7]
// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
//
//
// Note:
// 2 <= A.length <= 20000
// A.length % 2 == 0
// 0 <= A[i] <= 1000

#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) 
    {
        vector<int> ans (A.size());
        
        int evenIndex = 0;
        int oddIndex = 1;

        for(int i = 0; i < A.size(); ++i)
        {
            // 偶数的时候
            if(A[i] % 2 == 0)
            {
                ans[evenIndex] = A[i];
                evenIndex += 2;
            }
            // 奇数的时候
            else
            {
                ans[oddIndex] = A[i];
                oddIndex += 2;                   
            }
        }    

        return ans;
    }
};