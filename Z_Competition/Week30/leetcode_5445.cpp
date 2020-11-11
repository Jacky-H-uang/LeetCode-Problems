#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        vector<int> v(n);
        vector<int> ans;
        int sum = 0;
        v[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            v[i] = v[i-1] + nums[i];
            cout<<v[i]<<endl;
        }
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i]);
            for(int j=i+1;j<v.size();j++)
            {
                ans.push_back(v[j]-v[i]);
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=left-1;i<right;i++)
        {
            sum += ans[i];
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3,4};
    cout<<s.rangeSum(v,4,1,5)<<endl;
    system("pause");
    return 0;
}