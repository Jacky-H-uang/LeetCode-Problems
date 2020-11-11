//              257. 二叉树的所有路径
//
// 给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例:
// 输入:
//    1
//  /   \
// 2     3
//  \
//   5
// 输出: ["1->2->5", "1->3"]
// 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3



#include<bits/stdc++.h>
using namespace std;

// Easy

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* r,string str)
    {
        if(r != nullptr)
        {
            str += to_string(r->val);
        }

        // 叶子节点的时候直接加入 ans 然后返回
        if(r->left == nullptr && r->right == nullptr)
        {
            ans.push_back(str);
            return;
        }
        if(r->left)
        {
            dfs(r->left,str+"->");
        }
        if(r->right)
        {
            dfs(r->right,str+"->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
        {
            return ans;
        }
        
        dfs(root,"");

        return ans;
    }
};