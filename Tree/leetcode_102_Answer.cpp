// Binary Tree Level Order Traversal

// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Medium

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector <vector <int>> ret;
        if (!root) return ret;

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) 
            {
                auto node = q.front(); 
                q.pop();
                ret.back().push_back(node->val);
                if (node->left)     q.push(node->left);
                if (node->right)    q.push(node->right);
            }
        }
        return ret;
    }
};