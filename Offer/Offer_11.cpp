// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
//
// 示例 1：
// 输入：[3,4,5,1,2]
// 输出：1
//
// 示例 2：
// 输入：[2,2,2,0,1]
// 输出：0


#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    int minArray(vector<int>& numbers)
    {
        // 直接 sort 还是 binary search
        // BinarySearch 更快
        int len = numbers.size();
        int l = 0;
        int r = len-1;
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(numbers[mid] < numbers[r])
            {
                r = mid;
            }
            else if(numbers[mid] > numbers[r])
            {
                l = mid+1;
            }
            else
            {
                r--; 
            }
        }
        return numbers[r];
    }
};


int main()
{
    Solution s;
    vector<int> v = {2,2,2,0,1};
    cout<<s.minArray(v)<<endl;
    system("pause");
    return 0;
}