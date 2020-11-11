/*                                                          Subarray Sums Divisible by K                                                    */

// Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
//  
// Example 1:
// Input: A = [4,5,0,-2,-3,1], K = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by K = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//  
// Note:
// 1 <= A.length <= 30000
// -10000 <= A[i] <= 10000
// 2 <= K <= 10000


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Medium

//同余定理：P[j]-P[i-1] 连续的子数和
//         (P[j]-P[i-1]) mod K == 0
//         则P[j] mod K == P[i] mod K
//所以此题可以使用它的逆定理
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) 
    {
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0;i < A.size(); i++)
        {
            if(i == 0)
            {
                A[i] = (A[i] % K + K) % K;
                mp[A[i]]++;
            }
            else
            {
                A[i] = ((A[i]+A[i-1])%K+K)%K;
                mp[A[i]]++;
            }
        }
        int count = 0;
        for(auto[k,v]:mp)
        {
            count += (v*(v-1))/2;
        }
        return count;
    }
};


int main()
{
    vector<int> v = {4,5,0,-2,-3,1};
    Solution s;
    cout<<s.subarraysDivByK(v,5)<<endl;
    system("pause");
    return 0;
}