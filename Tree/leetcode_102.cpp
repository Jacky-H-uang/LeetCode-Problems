// Binary Tree Level Order Traversal

// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//Medium

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        int sign = 0; 
        vector<vector<int>> v;
        TreeNode* last = root;
        TreeNode* nlast = nullptr ;
        queue<TreeNode*> q;
        vector<int> t1;
        if(last!=nullptr)
        {
            q.push(last);
            while(!q.empty())
            {
                TreeNode* temp = q.front();
                q.pop();
                t1.push_back(temp->val);
                if(temp->left != nullptr)
                {
                    q.push(temp->left);
                    nlast = temp->left;
                }
                if(temp->right != nullptr)
                {
                    q.push(temp->right);
                    nlast = temp->right;
                }
                if(temp == last)
                {
                    v.push_back(t1);
                    t1.clear();
                    last = nlast;
                }
            }
        }
        return v;
    }
};


int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> r = s.levelOrder(root);
    for(auto& v : r)
    {
        for(auto& i :v)
        {
            cout<<i<<"  ";
        }
        cout<<"\n";
    }
    system("pause");
    return 0;
}