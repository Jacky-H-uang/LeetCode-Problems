#include<bits/stdc++.h>
using namespace std;

// Easy

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& p) {
        int lenA = arr.size();
        int lenP = p.size();

        for(int i = 0; i < p.size(); ++i)
        {
            bool flag = false;
            int k = p[i].size();
            for(int j = 0; j < arr.size()-k+1; ++j)
            {
                int t = 0;
                bool tmp = false;
                for(auto& m : p[i])
                {
                    if(m == arr[j+t])
                    {
                        flag = true;
                        tmp = true;
                    }
                    else
                    {
                        if(tmp == true)     return false;
                        flag = false;
                    }
                    ++t;
                }
                if(flag == true)    break;
            }
            if(flag == false)       return false;
        }
        
        return true;
    }
};