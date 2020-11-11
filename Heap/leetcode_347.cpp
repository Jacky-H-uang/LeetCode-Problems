//              347. 前 K 个高频元素
//
// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//
// 示例 1:
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
//
// 示例 2:
// 输入: nums = [1], k = 1
// 输出: [1]
//
// 提示：
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
// 你可以按任意顺序返回答案。


#include<bits/stdc++.h>
using namespace std;

// Medium
struct Num
{
    int a;
    int b;
};

class Solution {
public:
    struct cmp
    {
        bool operator()(Num x,Num y)
        {
            return x.b < y.b;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int len = nums.size();
        vector<int> ans;
        priority_queue<Num,vector<Num>,cmp> pq;
        unordered_map<int,int> Freq;
        for(int i = 0; i < len; ++i)
        {
            Freq[nums[i]]++;
        }
        auto it = Freq.begin();
        for(; it != Freq.end(); ++it)
        {
            Num t;
            t.a = it->first;
            t.b = it->second;
            pq.push(t); 
        }

        while(k > 0)
        {
            Num tmp = pq.top();
            ans.push_back(tmp.a);
            pq.pop();
            k--;
        }

        return ans;
    }
};