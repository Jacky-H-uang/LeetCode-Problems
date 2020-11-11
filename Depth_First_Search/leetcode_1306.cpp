#include<bits/stdc++.h>
using namespace std;

//Medium

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        vector<bool> Sign(len,false);
        function<bool(int)> dfs = [&](int pos) {
            if(pos >= len || pos < 0)
            {
                return false;
            }

            if(arr[pos] == 0)
            {
                return true;
            }

            if(Sign[pos] == false)
            {
                Sign[pos] = true;
                return dfs(pos + arr[pos]) || dfs(pos - arr[pos]);
            }
            else
            {
                return false;   
            }
        };  


        return dfs(start);   
    }
};