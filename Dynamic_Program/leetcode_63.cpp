// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//
//
// 说明：m 和 n 的值均不超过 100。
//
//
// 示例 1:
// 输入:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// 输出: 2
// 解释:
// 3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
// 1. 向右 -> 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右 -> 向右


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int len1 = obstacleGrid.size();
        int len2 = obstacleGrid[0].size();
        vector<vector<int>> dp(len1,vector<int>(len2,0));
        for(int i=0;i<len1;i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                break;
            }
            dp[i][0] = 1;
        }
        for(int i=0;i<len2;i++)
        {
            if(obstacleGrid[0][i] == 1)
            {
                break;
            }
            dp[0][i] = 1;
        }
        for(int i=1;i<len1;i++)
        {
            for(int j=1;j<len2;j++)
            {
                dp[i][j] = obstacleGrid[i][j] == 1?0:dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[len1-1][len2-1];
    }
};


int main()
{
    Solution s;
    vector<vector<int>> v = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<s.uniquePathsWithObstacles(v)<<endl;
    system("pause");
    return 0;
}