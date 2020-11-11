// 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
//
// 示例 1:
// 输入:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// 输出: 3
// 解释: 
// 长度最长的公共子数组是 [3, 2, 1]。
//
// 说明:
// 1 <= len(A), len(B) <= 1000
// 0 <= A[i], B[i] < 100


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
    	int lenA = A.size();
    	int lenB = B.size(); 
    	int res = 0;
    	vector<vector<int>> dp(lenA,vector<int>(lenB));
    	for(int i=0;i<lenA;i++)
    	{
    		if(A[i] == B[0])
    		{
    			dp[i][0] = 1;
    		}
    		else
    		{
    			dp[i][0] = 0;
    		}
    	}
       	for(int i=0;i<lenB;i++)
    	{
    		if(B[i] == A[0])
    		{
    			dp[0][i] = 1;
    			res = 1;
    		}
    		else
    		{
    			dp[0][i] = 0;
    		}
    	}
    	for(int i=1;i<lenA;i++)
    	{
    		for(int j=1;j<lenB;j++)
    		{
    			if(A[i] == B[j])
    			{
    				dp[i][j] = dp[i-1][j-1]+1;
    				res = max(dp[i][j],res);
    			}
    			else
    			{
    				dp[i][j] = 0;
    			}
    		}
    	}
    	return res;
    }
};