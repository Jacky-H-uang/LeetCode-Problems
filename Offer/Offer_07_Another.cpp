// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//
//  
// 例如，给出
// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：
//     3
//    / \
//   9  20
//     /  \
//    15   7
//  
// 限制：
//
// 0 <= 节点个数 <= 5000



#include<bits/stdc++.h>
#define NULL 0
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Medium

class Solution {
public:
    // 前序：根     左      右
    // 中序：左     根      右
    // 3    9   20   15   7
    // 9    3   15   20   7

    TreeNode* helper(vector<int>& pre,vector<int>& ino,int preBegin,int preEnd,int inoBegin,int inoEnd)
    {   
        if(preBegin > preEnd)
        {
            return 0;
        }
        TreeNode* root = new TreeNode(pre[preBegin]);
        if(preBegin == preEnd)
        {
            return root;
        }
        int L = 0;
        for(int i = inoBegin; i <= inoEnd; ++i)
        {
            if(pre[preBegin] == ino[i])
            {
                L = i-inoBegin;
                break;
            }
        }
        root->left = helper(pre,ino,preBegin+1,preBegin+L,inoBegin,inoBegin+L-1);
        root->right = helper(pre,ino,preBegin+1+L,preEnd,inoBegin+L+1,inoEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};