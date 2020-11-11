// 有一堆石头，每块石头的重量都是正整数。
// 每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。
// 那么粉碎的可能结果如下：
// 如果 x == y，那么两块石头都会被完全粉碎；
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
// 最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
// 
// 提示：
// 1 <= stones.length <= 30
// 1 <= stones[i] <= 1000


//Easy
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        int len = stones.size();
        sort(stones.begin(),stones.end());
        while(len>0)
        {
            if(len == 1)
            {
                return stones[0];
            }
            if(stones[len-2] == stones[len-1])
            {
                stones.pop_back();
                stones.pop_back();
                len = len-2;
                continue;
            }
            if(stones[len-2] < stones[len-1])
            {
                int a = stones[len-1]-stones[len-2];
                stones.pop_back();
                stones.pop_back();
                stones.push_back(a);
                sort(stones.begin(),stones.end());
                len = len-1;
            }
        }
        return 0;
    }
};
int main()
{
    vector<int> a;
    for(int i=0;i<10;i++)
    {
        a.push_back(i);
    }
    Solution s;
    int r = s.lastStoneWeight(a);
    cout<<r<<endl;
    system("pause");
    return 0;
}