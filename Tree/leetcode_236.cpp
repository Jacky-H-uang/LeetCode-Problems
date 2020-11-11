// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two 
// nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
//
// Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
//                       3
//                     /    \
//                    5      1
//                   / \    / \
//                  6   2  0   8
//                     / \
//                    7   4
//
// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
//
// Example 2:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
//  
//
// Note:
// All of the nodes' values will be unique.
// p and q are different and both values will exist in the binary tree.


#include<iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//Medium

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == nullptr)
        {
            return root;
        }
        if(root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left != nullptr && right != nullptr)
        {
            return root;
        }
        else if(left != nullptr && right == nullptr)
        {
            return left;
        }
        else if(left == nullptr && right != nullptr)
        {
            return right;
        }
        else
        {
            return nullptr;   
        }
    }
};


int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->right = new TreeNode(8);
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution s;
    TreeNode *r = s.lowestCommonAncestor(root,root->left,root->right);
    cout<<r->val<<endl;
    system("pause");
    return 0;
}