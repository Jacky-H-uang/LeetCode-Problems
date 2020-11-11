// 给定两个二叉树，编写一个函数来检验它们是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
// 示例 1:
// 输入:      1         1
//           / \       / \
//          2   3     2   3
//
//         [1,2,3],   [1,2,3]
// 输出: true
//
// 示例 2:
// 输入:      1          1
//           /           \
//          2             2
//
//         [1,2],     [1,null,2]
// 输出: false
//
// 示例 3:
// 输入:      1         1
//           / \       / \
//          2   1     1   2
//
//         [1,2,1],   [1,1,2]
// 输出: false


#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Easy

class Solution {                               // 递归
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==0 && q==0)
        {
            return true;
        }
        if(p==0 || q==0)
        {
            return false;
        }
        if(p->val!=q->val)
        {
            return false;
        }
        return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    }
};



int main()
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(1);

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(2);

    Solution s;
    bool r = s.isSameTree(t1,t2);
    if(r)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    system("pause");
    return 0;
}