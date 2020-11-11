// 给你一个数字数组 arr 。
// 如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
// 如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。
//
//
// 示例 1：
// 输入：arr = [3,5,1]
// 输出：true
// 解释：对数组重新排序得到 [1,3,5] 或者 [5,3,1] ，任意相邻两项的差分别为 2 或 -2 ，可以形成等差数列。
//
// 示例 2：
// 输入：arr = [1,2,4]
// 输出：false
// 解释：无法通过重新排序得到等差数列。



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Easy

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        int len = arr.size();
        sort(arr.begin(),arr.end());
        int dif = arr[1]-arr[0];
        for(int i=2;i<len;i++)
        {
            int temp = arr[i]-arr[i-1];
            if(temp != dif)
            {
                return false;
            }
        }
        return true;
    }
};