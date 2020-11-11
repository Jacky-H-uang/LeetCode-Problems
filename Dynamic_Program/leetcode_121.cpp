// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
// 注意：你不能在买入股票前卖出股票。
//
// 示例 1:
// 输入: [7,1,5,3,6,4]
// 输出: 5
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
//
// 示例 2:
// 输入: [7,6,4,3,1]
// 输出: 0
// 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

#include<iostream>
#include<vector>
using namespace std;

//Easy

class Solution1 {
public:
    int maxProfit(vector<int>& prices) 
    {
        int len = (int)prices.size();
        if(len<=0)
        {
            return 0;
        }
        int mi = prices[0];
        int ma = 0;
        for(int i=1;i<len;i++)
        {
            ma = max(ma,prices[i]-mi);
            mi = min(mi,prices[i]);
        }
        return ma;
    }
};

//单调栈的解法
//单调栈的作用是：用O(n)的时间得知所有位置两边第一个比他大(或小)的数的位置。
class Solution2 {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans = 0;
        vector<int> St;
        prices.emplace_back(-1);    // 哨兵????
        for (int i = 0; i < prices.size(); ++ i)
        {
            while (!St.empty() && St.back() > prices[i])        // 维护单调栈?
            {                 
                ans = max(ans, St.back() - St.front());         // 维护最大值
                St.pop_back();
            }
            St.emplace_back(prices[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    Solution2 s;
    int r = s.maxProfit(v);
    cout<<r<<endl;
    system("pause");
    return 0;
}