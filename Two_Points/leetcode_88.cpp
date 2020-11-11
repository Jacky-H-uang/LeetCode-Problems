// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//  
// 说明:
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//  
// 示例:
// 输入:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
// 输出: 
// [1,2,2,3,5,6]


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Easy

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int j = 0;
        for(int i=m;i<nums1.size();i++)
        {
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());
        int t = 1;
        cout<<"[";
        for(auto& i:nums1)
        {
            cout<<i;
            if(t<nums1.size())
            {
                cout<<",";
                t++;
            }
        }
        cout<<"]";
    }
};



int main()
{
    Solution s;
    vector<int> v1{1,0};
    vector<int> v2 = {2};
    s.merge(v1,1,v2,1);
    system("pause");
    return 0;
}