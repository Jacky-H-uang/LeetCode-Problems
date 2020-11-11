//                          530. 二叉搜索树的最小绝对差
//
// 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
//
//
// 示例：
// 输入：
//    1
//     \
//      3
//     /
//    2
// 输出：
// 1
//
//
// 解释：
// 最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。



#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> aux;
    void dfs(TreeNode* r)
    {
        if(r != NULL)
        {
            dfs(r->left);
            aux.emplace_back(r->val);
            dfs(r->right);
        }
    }
    int getMinimumDifference(TreeNode* root) 
    {
        dfs(root);
        int ans = INT_MAX;

        for(int i = 1; i < aux.size(); ++i)      ans = min(ans,abs(aux[i]-aux[i-1]));

        return ans;
    }
};