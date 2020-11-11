// 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例: 
// 给定如下二叉树，以及目标和 sum = 22，
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。


#include<iostream>3
#define NULL 0
using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root == 0)
        {
            return false;
        }
        if(root->left == 0 && root->right == 0)
        {
            return root->val == sum;
        }
        return hasPathSum(root->right,sum-root->val) || hasPathSum(root->left,sum-root->val);
    }
};