// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
// 注意：给定 n 是一个正整数。
//
// 示例 1：
// 输入： 2
// 输出： 2
// 解释： 有两种方法可以爬到楼顶。
// 1.  1 阶 + 1 阶
// 2.  2 阶
//
// 示例 2：
// 输入： 3
// 输出： 3
// 解释： 有三种方法可以爬到楼顶。
// 1.  1 阶 + 1 阶 + 1 阶
// 2.  1 阶 + 2 阶
// 3.  2 阶 + 1 阶

#include<iostream>
#include<vector>
using namespace std;

//Easy

class Solution1 {                       //暴力法 模拟全过程
public:
    int climbStairs(int n)
    {
        climbStairs(0,n);
    }
    int climbStairs(int m,int n)
    {
        if(m>n)
        {
            return 0;
        }
        if(m==n)
        {
            return 1;
        }
        return climbStairs(m+1,n)+climbStairs(m+2,n);
    }
};


class Solution2 {                       //动态规划
public:
    int climbStairs(int n)
    {
        if(n==1)
        {
            return 1;
        }
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class Solution3 {                      //记忆化递归         优化递归树
public:
    int climbStairs(int n)
    {
        vector<int> v(n+1);
        return climbStairs(0,n,v);
    }
    int climbStairs(int m,int n,vector<int> v)
    {
        if(m>n)
        {
            return 0;
        }
        if(m==n)
        {
            return 1;
        }
        if(v[m]>0)
        {
            return v[m];
        }
        v[m] = climbStairs(m+1,n,v)+climbStairs(m+2,n,v);
        return v[m];
    }
};





int main()
{
    Solution1 s;
    int r = s.climbStairs(4);
    cout<<r<<endl;
    system("pause");
    return 0;
}