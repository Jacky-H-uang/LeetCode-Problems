#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int func(int nE,int empty)
    {
        return empty / nE;
    }
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int ans = 0;
        int drink = numBottles;
        int empty = 0;
        while(drink)
        {
            ans += drink;
            empty += drink;
            drink = func(numExchange,empty);
            empty = empty % numExchange;
        }
        return ans;
    }
};


int main()
{
    Solution s;
    cout<<s.numWaterBottles(15,4)<<endl;
    system("pause");
    return 0;
}