//              637. 二叉树的层平均值
//
// 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
//
// 示例 1：
// 输入：
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 输出：[3, 14.5, 11]
// 解释：
// 第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
//
//
// 提示：
// 节点值的范围在32位有符号整数范围内。

#include<bits/stdc++.h>
using namespace std;

// Easy

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    vector<double> ans;
    void bfs(TreeNode* r)
    {
        vector<vector<int>> temp;
        queue<TreeNode*> q;
        q.push(r);
        while(!q.empty())
        {
            int len = q.size();
            double sum = 0;                 // 注意 sum 开 double
            for(int i = 0; i < len; ++i)
            {
                auto t = q.front();
                q.pop();
                sum += t->val;
                
                if(t->left != nullptr)
                {
                    q.push(t->left);
                }
                if(t->right != nullptr)
                {
                    q.push(t->right);
                }
            }

            ans.push_back((double)sum/len);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) 
    {
        bfs(root);
        return ans;
    }
};