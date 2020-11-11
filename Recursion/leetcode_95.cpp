// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
//  
//
// 示例：
// 输入：3
// 输出：
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
//
//
// 解释：
// 以上的输出对应以下 5 种不同结构的二叉搜索树：
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//  
//
// 提示：
// 0 <= n <= 8

#include<bits/stdc++.h>
using namespace std;

// Medium

//Definition for a binary tree node.
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
    // 递归回溯
    vector<TreeNode*> helper(int l,int r)
    {
        vector<TreeNode*> ans;
        if(l > r)
        {
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=l;i<=r;i++)
        {
            vector<TreeNode*> leftNodes = helper(l,i-1);
            vector<TreeNode*> rightNodes = helper(i+1,r);
            for(auto&ln:leftNodes)
            {
                for(auto&rn:rightNodes)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = ln;
                    root->right = rn;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) 
    {

        return n<=0?vector<TreeNode*>{} :helper(1,n);
    }
};