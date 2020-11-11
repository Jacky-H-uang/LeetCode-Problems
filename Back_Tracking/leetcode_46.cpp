//          46. 全排列
//
// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//
// 示例:
// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include<bits/stdc++.h>
using namespace std;

// Medium

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int len = nums.size();
        vector<vector<int>> ans;

        // 用来遍历的数组
        vector<int> temp;

        // 判段这个数是否选择了
        vector<bool> check(len,false);

        function<void()> dfs = [&](){
            // 跳出条件
            if(temp.size() == len)
            {
                ans.push_back(temp);
                return;
            }

            for(int i = 0; i < len; ++i)
            {
                // 如果没被选过的话就可以加入
                if(check[i] == false)
                {
                    temp.push_back(nums[i]);
                    check[i] = true;            // 改变状态 ， 向下遍历不能被选中
                    dfs();
                    temp.pop_back();            // 删除回溯
                    check[i] = false;           // 恢复状态 ，即下次的 dfs 可以被选中
                }
            }
       };

        dfs();

       return ans;
    }
};