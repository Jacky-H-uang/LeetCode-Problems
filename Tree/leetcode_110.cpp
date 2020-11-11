//      110. 平衡二叉树
//
// 给定一个二叉树，判断它是否是高度平衡的二叉树。
// 本题中，一棵高度平衡二叉树定义为：
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
//
//
// 示例 1:
// 给定二叉树 [3,9,20,null,null,15,7]
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回 true 。
//
//
// 示例 2:
// 给定二叉树 [1,2,2,3,3,null,null,4,4]
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// 返回 false 。


#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};


class Solution {
public:
    // 计算一个结点的最大深度
    int helper(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            return  max( helper(root->left) , helper(root->right) ) + 1; 
        }
    }
    bool isBalanced(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        else
        {
            // 一个个的比较每个结点的最大深度的差是不是小于 1
            return (helper(root->left)-helper(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);   
        }

        return false;
    }
};


// 更优的解法 （自底向上）---剪枝
class Solution2 {
public:
    int helper(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        // 从最左结点即最底部的结点开始计算
        int leftHeight = helper(root->left);              
        int rightHeight = helper(root->right);             

        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight-rightHeight) > 1)
        {
            return -1;
        }
        else
        {
            return max(leftHeight,rightHeight)+1;
        }
    }

    bool isBalanced(TreeNode* root)
    {
        return helper(root) >= 0;
    }
};