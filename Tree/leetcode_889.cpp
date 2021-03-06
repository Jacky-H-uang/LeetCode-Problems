// 返回与给定的前序和后序遍历匹配的任何二叉树。
// pre 和 post 遍历中的值是不同的正整数。
// 
// 示例：
// 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// 输出：[1,2,3,4,5,6,7]
//
// 提示：
// 1 <= pre.length == post.length <= 30
// pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
// 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。


//Medium

#include<bits/stdc++.h>
using namespace std;
#define NULL    0
//Definition for a binary tree node.
 struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1 |2 4 5| |3 6 7|
//  ------  ------
//  |4 5 2| |6 7 3| 1

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        int len = pre.size();
        if(len<=0)
        {
            return 0;
        }
        TreeNode *root = new TreeNode(pre[0]);
        if(len == 1)
        {
            return root;
        }
        else
        {
            int L = 0;
            for(int i=0;i<len;i++)
            {
                if(post[i] == pre[1])
                {
                    L = i+1;
                    break;
                }
            }
            vector<int> leftPre(pre.begin()+1,pre.begin()+1+L);
            vector<int> rightPre(pre.begin()+L+1,pre.end());
            vector<int> leftPost(post.begin(),post.begin()+L);
            vector<int> rightPost(post.begin()+L,post.end());
            root->left = constructFromPrePost(leftPre,leftPost);
            root->right = constructFromPrePost(rightPre,rightPost);
            return root;
        }
    }
};