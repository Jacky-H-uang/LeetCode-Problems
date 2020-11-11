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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int len = preorder.size();
        if(len <= 0)
        {
            return 0;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        if(len == 1)
        {
            return root;
        }
        else
        {
            int L = 0;
            for(int i = 0; i < len; ++i)
            {
                if(preorder[0] == inorder[i])
                {
                    L = i;
                    break;
                }
            }
            vector<int> leftPre(preorder.begin()+1,preorder.begin()+1+L);
            
            vector<int> rightPre(preorder.begin()+L+1,preorder.end());
            
            vector<int> leftIno(inorder.begin(),inorder.begin()+L);
            
            vector<int> rightIno(inorder.begin()+L+1,inorder.end());
            
            root->left = buildTree(leftPre,leftIno);
            root->right = buildTree(rightPre,rightIno);
            return root;
        }
    }
};