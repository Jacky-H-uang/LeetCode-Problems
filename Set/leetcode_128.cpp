/*                                                                      128. 最长连续序列                                                               */

// 给定一个未排序的整数数组，找出最长连续序列的长度。
// 要求算法的时间复杂度为 O(n)。
//
// 示例:
// 输入: [100, 4, 200, 1, 3, 2]
// 输出: 4
// 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。


#include<iostream>
#include<vector>
#include<set>
using namespace std;


// Hard

// 时间复杂度要求为O(n) 所以就不能使用sort()
// 所以就用空间换时间
// 使用 STL 的 set 来避免重复的元素 (set 默认升序)
// 考点 数据结构 hashmap set 使用
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int len = nums.size();
        set<int> s(nums.begin(),nums.end());
        int cur = 0;
        int res = 0;
        for(int i=0;i<len;i++)
        {
            if(s.find(nums[i]-1) == s.end())
            {
                cur = 1;
                while(s.find(nums[i] +cur) != s.end())
                {
                    cur++;
                }
                res = max(res,cur);
            }
        }
        return res;
    }
};


int main()
{
    Solution s;
    vector<int> v ={100,4,200,1,3,2};
    int r = s.longestConsecutive(v);
    cout<<r<<endl;
    system("pause");
    return 0;
}