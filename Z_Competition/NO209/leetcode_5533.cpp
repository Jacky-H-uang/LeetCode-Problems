#include<bits/stdc++.h>
using namespace std;

// Hard

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        while(n)
        {
            ans ^= n;
            n /= 2;
        }
        return ans;
    }
};