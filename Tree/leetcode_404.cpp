//          404. 左叶子之和
//
// 计算给定二叉树的所有左叶子之和。
//
// 示例：

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24


#include<bits/stdc++.h>
using namespace std;

// Easy

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isLeafNode(TreeNode* node) 
    {
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node) 
    {
        int ans = 0;
        if (node->left) 
        {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right)) 
        {
            ans += dfs(node->right);
        }
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};