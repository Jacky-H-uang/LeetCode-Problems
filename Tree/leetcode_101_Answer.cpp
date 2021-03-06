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
#include<queue>
#include<vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution1 {                                // 1. BFS
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
        {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v(size);
            for(int i=0;i<size;i++)
            {
                root = q.front();
                q.pop();
                v[i] = root ? root->val:INT_MIN;
                if(root)
                {
                    q.push(root->left);
                    q.push(root->right);
                }
            }
            for(int i=0;i<size/2;i++)
            {
                if(v[i] != v[size-1-i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};




class Solution2 {                               // 2. DFS           递归
public:
private:
    bool dfs(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == 0 && root2 == 0) 
        {
            return true;
        }
        if(root1 == 0 || root2 == 0) 
        {
            return false;
        }
        if(root1->val != root2->val) 
        {
            return false;
        }
        return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
    }

public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) 
        {
            return true;
        }
        return dfs(root->left, root->right);
    }
};