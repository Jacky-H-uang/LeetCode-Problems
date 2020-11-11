// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums。

// 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

// 你可以假设 nums1 和 nums2 不会同时为空。

// 示例 1:

// nums1 = [1, 3]
// nums2 = [2]

// 则中位数是 2.0
// 示例 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// 则中位数是 (2 + 3)/2 = 2.5

#include<vector>
#include<iostream>
using namespace std;

// Hard

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size())
        {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int len1 = nums1.size();
        int len2 = nums2.size();

        int l = 0;
        int r = len1;
        int totalLen = (len1+len2+1)/2;

        while(l<r)
        {
            int i = l+(r-l)/2;
            int j = totalLen-i;

            if(nums1[i] < nums2[j-1])
            {
                l = i+1;
            }
            else
            {
                r = i;   
            }
        }

        int t1 = l;
        int t2 = totalLen-t1;
        int nums1LeftMax = t1==0 ? INT_MIN:nums1[t1-1];
        int nums1RightMin = t1==len1 ? INT_MAX:nums1[t1];
        int nums2LeftMax = t2==0?INT_MIN:nums2[t2-1];
        int nums2RightMin = t2==len2?INT_MAX:nums2[t2];

        if((len1+len2)%2 == 0)
        {
            return (double)(max(nums1LeftMax,nums2LeftMax)+min(nums1RightMin,nums2RightMin))/2;
        }
        else
        {
            return max(nums1LeftMax,nums2LeftMax);
        }
    }
};

int main()
{
    vector<int> x1;
    x1.push_back(1);
    x1.push_back(3);

    vector<int> x2;
    x2.push_back(2);
    x2.push_back(4);
    
    Solution s;
    double rr = s.findMedianSortedArrays(x1,x2);
    cout<<rr<<endl;
    system("pause");
    return 0;
}
