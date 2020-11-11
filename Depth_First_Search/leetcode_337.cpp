//                  337. House Robber III
//
// The thief has found himself a new place for his thievery again. 
// There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. 
// After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
// It will automatically contact the police if two directly-linked houses were broken into on the same night.
// Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//
// Example 1:
// Input: [3,2,3,null,3,null,1]
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//
//
// Example 2:
// Input: [3,4,5,1,3,null,1]
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.


#include<bits/stdc++.h>
using namespace std;

// Medium

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    // 为什么我们用哈希映射然而不用数组
    // 因为我们选的其实是结点，但是返回的必须为 val
    // 所以用哈希映射 Key     : TreeNode* 
    //               Value   : val
    unordered_map<TreeNode*,int> Sel;           // 选根节点
    unordered_map<TreeNode*,int> NoSel;         // 不选根节点

    void dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        dfs(root->left);
        dfs(root->right);

        // 记忆存储 ： 选与不选
        Sel[root] = root->val + NoSel[root->left] + NoSel[root->right];
        NoSel[root] = max(Sel[root->left],NoSel[root->left]) + max(Sel[root->right],NoSel[root->right]);
    }

    int rob(TreeNode* root) 
    {
        dfs(root);
        return max(Sel[root] , NoSel[root]);
    }
};