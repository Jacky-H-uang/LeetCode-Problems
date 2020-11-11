// 给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，
// 使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。
// 如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。
//
// 请注意，答案不一定是 arr 中的数字。
//  
// 示例 1：
// 输入：arr = [4,9,3], target = 10
// 输出：3
// 解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
//
// 示例 2：
// 输入：arr = [2,3,5], target = 10o
// 输出：5
//
// 示例 3：
// 输入：arr = [60864,25176,27249,21296,20204], target = 56803
// 输出：11361
//  
// 提示：
// 1 <= arr.length <= 10^4
// 1 <= arr[i], target <= 10^5


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Medium

// 前缀法 + 二分查找
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) 
    {
        int len = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> p(len+1);
        int res = 0;
        int diff = target;                                              // 找出差最小的数
        int max_el = *max_element(arr.begin(),arr.end());               // 找出最大的范围
        for(int i=1;i<=len;i++)
        {
            p[i] = p[i-1]+arr[i-1];
        }
        for(int i=1;i<=max_el;i++)
        {
            auto it = lower_bound(arr.begin(),arr.end(),i);             // 二分查找，找出lower的位置
            int curr = p[it-arr.begin()] + (arr.end()-it)*i;
            if(abs(curr-target) < diff)
            {
                res = i;
                diff = abs(curr-target);
            }
        }
        return res;
    }
};



int main()
{
    vector<int> v = {4,9,3};
    int t = 10;
    Solution s;
    cout<<s.findBestValue(v,t)<<endl;
    system("pause");
    return 0;
}