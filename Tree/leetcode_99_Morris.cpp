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
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;
        TreeNode* predecessor = nullptr;

        while (root != nullptr) 
        {
            if (root->left != nullptr) 
            {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) 
                {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) 
                {
                    predecessor->right = root;
                    root = root->left;
                }

                // 说明左子树已经访问完了，我们需要断开链接
                else 
                {
                    if (pred != nullptr && root->val < pred->val) 
                    {
                        y = root;
                        if (x == nullptr) 
                        {
                            x = pred;
                        }
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            }

            // 如果没有左孩子，则直接访问右孩子
            else {
                if (pred != nullptr && root->val < pred->val) 
                {
                    y = root;
                    if (x == nullptr) 
                    {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};