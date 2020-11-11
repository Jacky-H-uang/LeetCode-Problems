// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
// 找出 nums 中的三个整数，使得它们的和与 target 最接近。
// 返回这三个数的和。假定每组输入只存在唯一答案。
//
// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
//
// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Medium

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int close = nums[0] + nums[1] + nums[2];
        int len = nums.size();
        for(int i=0;i<len-2;i++)
        {
            int l = i+1;
            int r = len-1;
            while(l<r)
            {
                int temp = nums[i] + nums[l] +nums[r];
                if(abs(temp-target) < abs(close-target))
                {
                    close = temp;
                }
                if(temp > target)
                {
                    r--;
                }
                else if(temp < target)
                {
                    l++;
                }
                else
                {
                    return target;
                }
            }
        }
        return close;
    }
};


int main()
{
    Solution s;
    vector<int> n = {-3,-2,-5,3,-4};
    int r = s.threeSumClosest(n,-1);
    cout<<r<<endl;
    system("pause");
    return 0;
}