//              538. 把二叉搜索树转换为累加树
//
// 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
//
//
// 例如：
// 输入: 原始二叉搜索树:
//               5
//             /   \
//            2     13

// 输出: 转换为累加树:
//               18
//             /    \
//           20      13


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


// Morris遍历  ---?
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
    }
};