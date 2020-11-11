// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 >= s 的长度最小的连续子数组，并返回其长度。
// 如果不存在符合条件的连续子数组，返回 0。
//  
// 示例：
// 输入：s = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的连续子数组。
//  
// 进阶：
// 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

#include<iostream>
#include<vector>
using namespace std;

// Medium

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
    	int len = nums.size();
        if(len <= 0)
        {
            return 0;
        }
    	int sum = 0;
    	int count = INT_MAX;
    	int p1 = 0;
    	int p2 = 0;
    	for(int i=0;i<len;i++)
    	{
    		sum += nums[i];
    		nums[i] = sum;
    	}
    	while(p2<len)
    	{
    		if(nums[p2] >= s)
    		{
    			count = min(count,p2+1);
    		}
    		if(nums[p1] >= s)
    		{
    			count = min(count,p1+1);
    		}
    		if(nums[p2]-nums[p1] >= s)
    		{
    			count = min(count,p2-p1);
    			p1++;
    			continue;
    		}
    		p2++;
    	}
        if(count == INT_MAX)
        {
            count = 0;
        }
    	return count;
    }
};



int main()
{
	Solution s;
	vector<int> v = {2,3,1,2,4,3};
	cout<<s.minSubArrayLen(7,v)<<endl;
	return 0; 
}