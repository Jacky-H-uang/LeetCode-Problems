/*                                      Maximum Depth of Binary Tree                                      */

// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7



#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Easy

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        int sign = 0;
        TreeNode* last = root;
        TreeNode* nlast = nullptr;
        queue<TreeNode*> q;
        vector<int> t1;
        if(last!=nullptr)
        {
            q.push(last);
            while(!q.empty())
            {
                TreeNode* temp = q.front();
                q.pop();
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
                    sign++;
                    last = nlast;
                }
            }
        }
        return sign;
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

    cout<<s.maxDepth(root)<<endl;
    system("pause");
    return 0;
}