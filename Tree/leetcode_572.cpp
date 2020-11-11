// Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s.
// A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
//
// Example 1:
// Given tree s:
//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4 
//   / \
//  1   2
// Return true, because t has the same structure and node values with a subtree of s.
//  
// Example 2:
// Given tree s:
//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.


#include<iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Easy

class Solution {
public:
    bool isEqual(TreeNode* t1, TreeNode* t2) 
    {
        if(t1 == nullptr && t2 == nullptr)
        {
            return true;
        }
        if(t1 == nullptr || t2 == nullptr)
        {
            return false;
        }
        if(t1->val != t2->val)
        {
            return false;
        }
        return isEqual(t1->left,t2->left) && isEqual(t1->right,t2->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if(s == nullptr && t == nullptr)
        {
            return true;
        }
        if(s == nullptr && t != nullptr)
        {
            return false;
        }
        return isEqual(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};


int main()
{
    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(4);
    t1->right = new TreeNode(5);
    t1->left->left = new TreeNode(1);
    t1->left->right = new TreeNode(2);
    t1->left->right->left = new TreeNode(0);

    TreeNode* t2 = new TreeNode(4);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(2);
    Solution s;
    bool r = s.isSubtree(t1,t2);
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
