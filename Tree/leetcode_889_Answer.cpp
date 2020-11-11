// �����������ǰ��ͺ������ƥ����κζ�������
// pre �� post �����е�ֵ�ǲ�ͬ����������
// 
// ʾ����
// ���룺pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// �����[1,2,3,4,5,6,7]
//
// ��ʾ��
// 1 <= pre.length == post.length <= 30
// pre[] �� post[] ���� 1, 2, ..., pre.length ������
// ÿ�����뱣֤������һ���𰸡�����ж���𰸣����Է�������һ����


//Medium
#include<iostream>
#include<vector>
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

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {   
        int len = post.size()-1;
        return buildTree(pre, post, 0,len,0,len);
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& post, int preBegin,int preEnd,int postBegin,int postEnd) 
    {
        if(preBegin == preEnd)
        {
            return new TreeNode(pre[preBegin]);
        }
        if(preBegin>preEnd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[preBegin]);   
        int temp = pre[preBegin+1];
        for(int i = postBegin;i<=postEnd;i++)
        {
            if(post[i] == temp)
            {
                int le = i-postBegin;
                root->left = buildTree(pre,post,preBegin+1,preBegin+le+1,postBegin,i);
                root->right = buildTree(pre,post,preBegin+le+2,preEnd,i+1,postEnd-1);
                return root;
            }
        }
        return NULL;
    }
};