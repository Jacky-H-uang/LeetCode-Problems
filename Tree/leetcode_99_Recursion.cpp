// 99. Recover Binary Search Tree
//
// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.
//
//
// Example 1:
// Input: [1,3,null,null,2]
//    1
//   /
//  3
//   \
//    2
// Output: [3,1,null,null,2]
//    3
//   /
//  1
//   \
//    2
//
//
// Example 2:
// Input: [3,1,4,null,null,2]
//   3
//  / \
// 1   4
//    /
//   2
// Output: [2,1,4,null,null,3]
//   2
//  / \
// 1   4
//    /
//   3
//
//
// Follow up:
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?



#include<bits/stdc++.h>
using namespace std;

// Hard

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




class Solution {
private:
    TreeNode* x;
    TreeNode* y;
    TreeNode* pred;                     // 维护一个前驱结点
public:
    void inorder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder(root->left);
        if(pred != nullptr && root->val < pred->val)
        {
            y = root;
            if(x == nullptr)
            {
                x = pred;
            }
            else
            {
                return;
            }
        }
        pred = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        inorder(root);

        // 交换错误结点 x  y
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
};