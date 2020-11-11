// 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： 
// counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
//
// 示例:
// 输入: [5,2,6,1]
// 输出: [2,1,1,0] 
// 解释:
// 5 的右侧有 2 个更小的元素 (2 和 1).
// 2 的右侧仅有 1 个更小的元素 (1).
// 6 的右侧有 1 个更小的元素 (1).
// 1 的右侧有 0 个更小的元素.



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    // 归并排序
    // 比较的原数组，而实际操作的为索引数组
    // 在交换索引的时候来操作记录返回数组
    
    vector<int> aux;            // 辅助数组
    vector<int> index;          // 索引数组
    vector<int> res;            // 返回数组     

    void merge_sort(vector<int>&nums,int lo,int hi,vector<int>& index)
    {
        if(hi <= lo)    return;
        int mid = lo + (hi-lo)/2;
        merge_sort(nums,lo,mid,index);
        merge_sort(nums,mid+1,hi,index);
        merge(nums,lo,mid,hi,index);
    }
    void merge(vector<int>& nums,int lo,int mid,int hi,vector<int>& index)
    {
        int i = lo;
        int j = mid+1;
        for(int k = lo;k <= hi;k++)
        {
            aux[k] = index[k];
        }
        for(int k=lo; k <= hi; k++)
        {
            if(i > mid)
            {
                index[k] = aux[j++];
            }
            else if(j > hi)
            {
                index[k] = aux[i++];
                res[index[k]] += hi - mid;
            }
            else if(nums[aux[i]] > nums[aux[j]])
            {
                index[k] = aux[j++];
            }
            else
            {
                index[k] = aux[i++];
                res[index[k]] += (j-mid-1);             // mid+1 ~ j-1 之间的所有数都是小于当前的
            }
        }
    }


public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int len = nums.size();
        aux = vector<int>(len);
        index = vector<int>(len);
        res = vector<int>(len);
        for(int i = 0;i<len;i++)
        {
            index[i] = i;
        }
        merge_sort(nums,0,len-1,index);
        return res;
    }
};



int main()
{
    Solution s;
    vector<int> rr = {1,2,3,4,5};
    vector<int> r = s.countSmaller(rr);
    for(auto&i:r)
    {
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}