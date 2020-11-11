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

class Solution              //双指针从后往前 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int p1 = m-1;
        int p2 = n-1;
        int p = m+n-1;
        if(p1<0)
        {
            nums1 = nums2;
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
            return;
        }
        while(p2>=0)
        {
            if(p1<0 || nums2[p2] > nums1[p1])
            {
                nums1[p] = nums2[p2];
                p2--;
                p--;
            }
            else
            {
                nums1[p] = nums1[p1];
                p--;
                p1--;
            }
        }
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
    vector<int> v1{2,0};
    vector<int> v2 = {1};
    s.merge(v1,1,v2,1);
    system("pause");
    return 0;
}