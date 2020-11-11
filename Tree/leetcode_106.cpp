//                  106. 从中序与后序遍历序列构造二叉树
//
// 根据一棵树的中序遍历与后序遍历构造二叉树。
// 注意:
// 你可以假设树中没有重复的元素。
//
// 例如，给出
// 中序遍历 inorder = [9,3,15,20,7]
// 后序遍历 postorder = [9,15,7,20,3]
// 返回如下的二叉树：
//     3
//    / \
//   9  20
//     /  \
//    15   7


#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 中序遍历：左     根      右
// 后序遍历：左     右      根
// 9   3   15  20  7
// 9   15   7  20  3

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = postorder.size();

        if(len == 0)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[len-1]);

        int L = 0;
        for(int i = 0; i < len; ++i)
        {
            if(inorder[i] == postorder[len-1])
            {
                L = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(),inorder.begin()+L);
        vector<int> rightInorder(inorder.begin()+L+1,inorder.end());
        vector<int> leftPostorder(postorder.begin(),postorder.begin()+L);
        vector<int> rightPostorder(postorder.begin()+L,postorder.end()-1);

        root->left = buildTree(leftInorder,leftPostorder);
        root->right = buildTree(rightInorder,rightPostorder);

        return root;
    }
};