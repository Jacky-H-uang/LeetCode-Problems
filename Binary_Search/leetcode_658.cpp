// 给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。
//返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

// 示例 1:
// 输入: [1,2,3,4,5], k=4, x=3
// 输出: [1,2,3,4]

// 示例 2:
// 输入: [1,2,3,4,5], k=4, x=-1
// 输出: [1,2,3,4]

// 说明:
// k 的值为正数，且总是小于给定排序数组的长度。
// 数组不为空，且长度不超过 104
// 数组里的每个元素与 x 的绝对值不超过 104

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//二分查找
class Solution1 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int len = arr.size();
        int end = len-k;
        int start = 0;
        while(start<end)
        {
            int mid = (start+end)/2;
            if(x-arr[mid] > arr[mid+k]-x)
            {
                start = mid+1;
            }
            else
            {
                end = mid;
            }
        }
        return vector<int>(arr.begin()+start,arr.begin()+start+k);
    }
};
//multimap 解
class Solution2
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multimap<int,int> mp;
        vector<int> result;
        for(int i=0;i<arr.size();++i)
        {
            mp.insert(pair<int,int>(abs(arr[i]-x),i));
        }
        multimap<int,int>::iterator it = mp.begin();
        for(int j=0;j<k;++j)
        {
            result.push_back(arr[it->second]);
            ++it;
        }
        sort(result.begin(),result.end());
        return result;
    }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    Solution1 s;
    vector<int> r = s.findClosestElements(v,1,9);
    vector<int>::iterator it = r.begin();
    for(;it!=r.end();it++)
    {
        cout<<*it<<" ";
    }
    system("pause");
    return 0;
}