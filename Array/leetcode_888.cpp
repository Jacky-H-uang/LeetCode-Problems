//                                      888. 公平的糖果棒交换
//
// 爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。
// 因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）
// 返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。
// 如果有多个答案，你可以返回其中任何一个。保证答案存在。
//
//
// 示例 1：
// 输入：A = [1,1], B = [2,2]
// 输出：[1,2]
//
// 示例 2：
// 输入：A = [1,2], B = [2,3]
// 输出：[1,2]
//
// 示例 3：
// 输入：A = [2], B = [1,3]
// 输出：[2,3]
//
// 示例 4：
// 输入：A = [1,2,5], B = [2,4]
// 输出：[5,4]
//
// 提示：
// 1 <= A.length <= 10000
// 1 <= B.length <= 10000
// 1 <= A[i] <= 100000
// 1 <= B[i] <= 100000
// 保证爱丽丝与鲍勃的糖果总量不同。
// 答案肯定存在。


#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sA = accumulate(A.begin(),A.end(),0);
        int sB = accumulate(B.begin(),B.end(),0);
        int s = (sA + sB ) / 2;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        vector<int> ans;
        int dif = sA - s;           // 求差值
        int i = 0; 
        int j = 0;
        // 类似归并排序的合并一样找出相差 dif 的一对
        while(i < A.size() && j < B.size()) {
            if(A[i] - B[j] < dif) {
                i++;
            }
            else if(A[i] - B[j] > dif) {
                j++;
            }
            else {
                ans.push_back(A[i]);
                ans.push_back(B[j]);
                break;
            }
        }
        return ans;
    }
};