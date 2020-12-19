#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // 先做一次矩阵的转置 然后再对每一层来 reverse
        for(int i = 0; i < m; ++i)
        {
            for(int j = i; j < n; ++j)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // 对每一行来取反
        for(int i = 0 ; i < m; ++i)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};