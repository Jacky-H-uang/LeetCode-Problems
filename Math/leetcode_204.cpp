#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    // 埃拉托斯特尼筛法
    // 利用之前求出的质数来筛选之后不可能为质数的数
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        int count = 0;
        
        for(int i = 2; i < n;++i) {
            if(isPrime[i]) {
                ++count;
                for(int j = 2 ; i*j < n ; ++j){
                    isPrime[i*j] = false;
                }
            }
        }

        return count;
    }
};