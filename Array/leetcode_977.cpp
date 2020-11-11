//                                  977. Squares of a Sorted Array
//
// Given an array of integers A sorted in non-decreasing order, 
// return an array of the squares of each number, also in sorted non-decreasing order.
//
//
// Example 1:
// Input: [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
//
//
// Example 2:
// Input: [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
//
//
// Note:
// 1 <= A.length <= 10000
// -10000 <= A[i] <= 10000
// A is sorted in non-decreasing order.


#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        int len = A.size();
        vector<int> ans(len);

        int L = 0 , R = len - 1 , pos = R;
        while(L <= R) {
            if(abs(A[L]) < abs(A[R]))
            {
                ans[pos] = pow(A[R],2);
                R--;
                pos--;
            }
            else
            {
                ans[pos] = pow(A[L],2);
                L++;
                pos--;
            }
        }

        return ans;
    }
};