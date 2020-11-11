// 给定两个数组，编写一个函数来计算它们的交集。
//  
//
// 示例 1：
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2,2]
//
// 示例 2:
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出：[4,9]
//  
// 
// 说明：
// 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
// 我们可以不考虑输出结果的顺序。
//
// 进阶：
// 如果给定的数组已经排好序呢？你将如何优化你的算法？
// 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
// 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Easy

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        vector<int> intersection;
        int index1 = 0, index2 = 0;
        while (index1 < length1 && index2 < length2) 
        {
            if (nums1[index1] < nums2[index2]) 
            {
                index1++;
            } 
            else if (nums1[index1] > nums2[index2]) 
            {
                index2++;
            } 
            else 
            {
                intersection.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return intersection;
    }
};


int main()
{
    Solution s;
    vector<int> n1 = {1};
    vector<int> n2 = {1,1};
    for(auto& i:s.intersect(n1,n2))
    {
        cout<<i<<"  ";
    }
    system("pause");
    return 0;
}