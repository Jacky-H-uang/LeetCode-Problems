// 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
//
// 注意:
// 数组长度 n 满足以下条件:
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
//
// 示例:
// 输入:
// nums = [7,2,5,10,8]
// m = 2
// 输出:
// 18
//
//
// 解释:
// 一共有四种方法将nums分割为2个子数组。
// 其中最好的方式是将其分为[7,2,5] 和 [10,8]，
// 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。


#include<bits/stdc++.h>
using namespace std;

// Hard

class Solution {
public:
    // 取得分出来的数组中最大的值中最小的
    int splitArray(vector<int>& nums, int m)
    {   
        int len = nums.size();
        int nums_max = nums[max_element(nums.begin(),nums.end())-nums.begin()];
        long nums_sum = accumulate(nums.begin(),nums.end(),0L);

        int left = nums_max;
        long right = nums_sum;

        while(left < right)
        {
            int mid = left + (right-left)/2;
            int count = 0;
            long num = 0;
            for(auto& i:nums)
            {
                if(num + i <= mid)
                {
                    num += i;
                }
                else
                {
                    count++;   
                    num = i;
                }
            }

            if(count < m)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;   
            }
        }
        return left;
    }
};


int main()
{
    Solution s;
    vector<int> v = {7,2,5,10,8};
    cout<<s.splitArray(v,2)<<endl;
    system("pause");
    return 0;
}