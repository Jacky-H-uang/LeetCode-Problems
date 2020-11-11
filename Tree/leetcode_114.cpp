// 给定一个二叉树，原地将它展开为一个单链表。
//  
// 例如，给定二叉树
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
//
// 将其展开为：
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

#include<bits/stdc++.h>
using namespace std;

// Medium


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* last = nullptr;
    void flatten(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;
        last = root;
    }
};