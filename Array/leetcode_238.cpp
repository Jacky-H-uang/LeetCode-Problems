/*                                                                      238. 除自身以外数组的乘积                                                                   */

// 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//  
// 示例:
// 输入: [1,2,3,4]
// 输出: [24,12,8,6]
//  
// 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
//
// 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//
// 进阶：
// 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）



#include<iostream>
#include<vector>
using namespace std;

// Medium


// 左右 两个数组
// 前缀法 + 后缀法
// Q：常数空间复杂度内完成这个题目？？？
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int len = nums.size();
        vector<int> left(len);
        vector<int> right(len);
        vector<int> output(len);
        int l = 1;
        int r = 1;
        for(int i=0;i<len;i++)
        {
            left[i] = l;
            l *= nums[i];
        }
        for(int i=len-1;i>=0;i--)
        {
            right[i] = r;
            r *= nums[i];
        }
        for(int i=0;i<len;i++)
        {
            output[i] = left[i]*right[i];
        }
        return output;
    }
};


int main()
{
    vector<int> v = {1,2,3,4};
    Solution s;
    vector<int> res = s.productExceptSelf(v);
    for(auto& i:res)
    {
        cout<<i<<"  ";
    }
    system("pause");
    return 0;
}