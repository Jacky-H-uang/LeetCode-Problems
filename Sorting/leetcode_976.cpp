//                                  976. Largest Perimeter Triangle
//
// Given an array A of positive lengths, 
// return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.
// If it is impossible to form any triangle of non-zero area, return 0.
//
//
// Example 1:
// Input: [2,1,2]
// Output: 5
//
// Example 2:
// Input: [1,2,1]
// Output: 0
//
// Example 3:
// Input: [3,2,3,4]
// Output: 10
//
// Example 4:
// Input: [3,6,2,3]
// Output: 8
//
// 
// Note:
// 3 <= A.length <= 10000
// 1 <= A[i] <= 10^6



#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if(A.size() < 3)        return 0;
        
        sort(A.begin(),A.end(),less<int>());
        int i = A.size()-1;
        int j = i-1;
        int k = j-1;     

        int ans = 0;

        while(k >= 0) {
            if(A[k] + A[j] > A[i])
            {
                ans = A[k] + A[j] + A[i];
                break;
            }
            else
            {
                k--;
                j--;
                i--;
            }
        }

        return ans;
    }
};