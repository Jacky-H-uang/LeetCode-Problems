// 99. Recover Binary Search Tree
//
// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.
//
//
// Example 1:
// Input: [1,3,null,null,2]
//    1
//   /
//  3
//   \
//    2
// Output: [3,1,null,null,2]
//    3
//   /
//  1
//   \
//    2
//
//
// Example 2:
// Input: [3,1,4,null,null,2]
//   3
//  / \
// 1   4
//    /
//   2
// Output: [2,1,4,null,null,3]
//   2
//  / \
// 1   4
//    /
//   3
//
//
// Follow up:
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?



#include<bits/stdc++.h>
using namespace std;

// Hard

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




class Solution {
public:
    // 中序遍历整个二叉树 ， 然后将遍历结果保存到一个数组 nuns 里面
    void inorder(TreeNode* root,vector<int>& nums)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }

    // 找到其中错误交换的两个结点
    pair<int,int>findTwoSwapped(vector<int>& nums)
    {
        int n = nums.size();
        int x = -1;
        int y = -1;
        for(int i = 0; i < n-1; ++i)
        {
            // 前面比后面大的时候就找到了错误的结点
            if(nums[i] > nums[i+1])
            {
                y = nums[i+1];
                if(x == -1)
                {
                    x = nums[i];
                }
                else
                {
                    break;
                }
            }
        }
        return {x,y};
    }

    // 恢复错误结点, 再次中序遍历
    void recover(TreeNode* r,int count,int x,int y)
    {
        if(r != nullptr)
        {
            if(r->val == x || r->val == y)
            {
                r->val = r->val == x? y : x;
                if(--count == 0)
                {
                    return;
                }
            }
            recover(r->left,count,x,y);
            recover(r->right,count,x,y);
        }
    }

    void recoverTree(TreeNode* root) 
    {
        vector<int> nums;
        inorder(root,nums);
        pair<int,int> swapped = findTwoSwapped(nums);
        recover(root,2,swapped.first,swapped.second);       // 2表示交换一次 x  交换一次 y
    }
};