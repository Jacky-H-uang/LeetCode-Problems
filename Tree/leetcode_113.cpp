//              113. 路径总和 II
//
// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例:
// 给定如下二叉树，以及目标和 sum = 22，
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]


#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Medium

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> seq;

    void dfs(TreeNode* r,int sum)
    {
        if(r == NULL)       return;
        seq.push_back(r->val);

        // 注意要求路径的结束节点必须是叶子节点
        if(r->val == sum && r->left == NULL && r->right == NULL)
        {
            ans.push_back(seq);
        }

        dfs(r->left,sum - r->val);
        dfs(r->right,sum - r->val);
        seq.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        
        return ans;
    }
};