// 给定两个大小为 m 和 n 的有序数组nums1 和nums2。

// 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为O(log(m + n))。

// 你可以假设nums1和nums2不会同时为空。

// 示例 1:

// nums1 = [1, 3]
// nums2 = [2]

// 则中位数是 2.0
// 示例 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// 则中位数是 (2 + 3)/2 = 2.5
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    struct cmp
    {
        bool operator()(int x,int y)
        {
            return x > y;
        }
    };

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        priority_queue<int,vector<int>,cmp> pqueue;
        for(auto i:nums1)
        {
            pqueue.push(i);
        }
        for(auto j:nums2)
        {
            pqueue.push(j);
        }
        int SIZE = pqueue.size();
        double result = 0;
        if(SIZE%2==0)
        {
            int t1 = SIZE/2;
            int t2 = t1 + 1;
            for(int i=1;i<t1;i++)
            {
                pqueue.pop();
            }
            int temp = pqueue.top();
            pqueue.pop();
            result = (temp + pqueue.top())/2;
        }
        else
        {
            int t1 = SIZE/2+1;
            for(int i=1;i<t1;i++)
            {
                pqueue.pop();
            }
            double r1 = pqueue.top();
            result = r1/1.0;
        }
        return result;
    }
};

int main()
{
    vector<int> x1;
    x1.push_back(1);
    x1.push_back(3);

    vector<int> x2;
    x2.push_back(2);
    //x2.push_back(4);
    
    Solution s;
    double rr = s.findMedianSortedArrays(x1,x2);
    cout<<rr<<endl;
    system("pause");
    return 0;
}
