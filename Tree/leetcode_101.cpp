// 给定一个二叉树，检查它是否是镜像对称的。
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
// 进阶：
// 你可以运用递归和迭代两种方法解决这个问题吗？



#include<iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {                                // 递归
public:
    bool isMirror(TreeNode* t1,TreeNode* t2)
    {
        if(t1 == nullptr && t2 == nullptr)
        {
            return true;
        }
        if(t1 == nullptr || t2 == nullptr)
        {
            return false;
        }
        return (t1->val == t2->val) && isMirror(t1->right,t2->left) && isMirror(t1->left,t2->right);
    }

    bool isSymmetric(TreeNode* root) 
    {
        return isMirror(root,root);
    }
};

int main()
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(1);

    Solution s;
    bool r = s.isSymmetric(t1);
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