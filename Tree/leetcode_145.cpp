//           145. 二叉树的后序遍历
//
// 给定一个二叉树，返回它的 后序 遍历。
//
// 示例:
// 输入: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 
// 输出: [3,2,1]
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？


#include<bits/stdc++.h>
using namespace std;

//Medium

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
    vector<int> ans;
    void func(TreeNode* root)
    {
        if(root == NULL)       return;
        func(root->left);
        func(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        func(root);
        return ans;
    }
};