// 在未排序的数组中找到第 k 个最大的元素。
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
// 示例 1:
// 输入: [3,2,1,5,6,4] 和 k = 2
// 输出: 5
//
// 示例 2:
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
// 输出: 4
//
// 说明:
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。


#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:
    struct cmp
    {
        bool operator()(int a,int b)
        {
            return a < b;
        }
    };
    
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,cmp> pq;
        for(auto& i:nums)
        {
            pq.push(i);
        }
        for(int i=0;i<k-1;i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    Solution s;
    vector<int> v = {3,2,3,1,2,4,5,5,6};
    cout<<s.findKthLargest(v,4)<<endl;
    system("pause");
    return 0;
}