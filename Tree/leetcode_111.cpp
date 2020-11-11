//      111. 二叉树的最小深度
//
//
// 给定一个二叉树，找出其最小深度。
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
// 说明: 叶子节点是指没有子节点的节点。
//
//
// 示例:
// 给定二叉树 [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最小深度  2.

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Easy


class Solution {
public:
    int helper(TreeNode* r)
    {
        if(r == NULL)
        {
            return 0;
        }

        // 左右都为空就返回 1
        if(r->left == NULL && r->right == NULL)
        {
            return 1;
        }

        // 保持返回的是叶子节点
        if(r->left == NULL || r->right == NULL)
        {
            return 1 + (r->left == NULL? helper(r->right) : helper(r->left));
        }
        
        return min(1 + helper(r->left),1 + helper(r->right));
    }

    int minDepth(TreeNode* root) 
    {
        return helper(root);
    }
};