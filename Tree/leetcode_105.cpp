/*      Construct Binary Tree from Preorder and Inorder Traversal         */

// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:
//     3
//    / \
//   9  20
//     /  \
//    15   7



#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Medium

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int len = preorder.size();
        if(len<=0)
        {
            return 0;
        }
        TreeNode *root = new TreeNode(preorder[0]);

        if(len == 1)
        {
            return root;
        }
        else
        {
            int L = 0;
            for(int i=0;i<len;i++)
            {
                if(inorder[i] == preorder[0])
                {
                    L = i;
                    break;
                }
            }
            vector<int> lPreprder(preorder.begin()+1,preorder.begin()+1+L);
            vector<int> rPreorder(preorder.begin()+L+1,preorder.end());
            vector<int> lInorder(inorder.begin(),inorder.begin()+L);
            vector<int> rInorder(inorder.begin()+L+1,inorder.end());

            root->left = buildTree(lPreprder,lInorder);
            root->right = buildTree(rPreorder,rInorder);
        }
        return root;
    }
};