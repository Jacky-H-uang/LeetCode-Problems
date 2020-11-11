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