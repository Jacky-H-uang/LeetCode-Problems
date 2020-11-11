// 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
//
// 示例:
// 输入: 3
// 输出: 5
// 解释:
// 给定 n = 3, 一共有 5 种不同结构的二叉搜索树: 
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3



#include<iostream>
#include<vector>
using namespace std;

// Medium



class Solution {
public:
    // 利用卡塔兰（Catlan）数 Cn
    // C0 = 1, Cn+1 = Cn*2(2n+1)/(n+2)
    int numTrees(int n) 
    {
        long long C = 1;
        for (int i = 0; i < n; ++i) 
        {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};