//          109. Convert Sorted List to Binary Search Tree
//
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//  
//
// Example 1:
// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
//
//
// Example 2:
// Input: head = []
// Output: []
//
//
// Example 3:
// Input: head = [0]
// Output: [0]
//
//
// Example 4:
// Input: head = [1,3]
// Output: [3,1]
//  
//
// Constraints:
// The numner of nodes in head is in the range [0, 2 * 10^4].
// -10^5 <= Node.val <= 10^5


#include<bits/stdc++.h>
using namespace std;

// Medium

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 分治法
class Solution {
public:
    // 快慢指针法来得到中间的元素
    ListNode* getMid(ListNode* left,ListNode* right)
    {
        ListNode* fast = left;
        ListNode* slow = left;
        while(fast != right && fast->next != right)
        {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* buildTree(ListNode* l,ListNode* r)
    {
        if(l == r)
        {
            return nullptr;
        }
        ListNode* mid = getMid(l,r);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(l,mid);
        root->right = buildTree(mid->next,r);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) 
    {
        return buildTree(head,nullptr);
    }
};



// 优化  -- 分治 + 中序遍历
class Solution2 {
public:
    int getLength(ListNode* head)
    {
        int cnt = 0;
        for(;head != nullptr;++cnt,head = head->next);
        return cnt;
    }

    // 利用中序遍历来构建二叉平衡树
    TreeNode* buildTree(ListNode*& head,int l,int r)
    {
        // 遍历到空节点
        if(l > r)
        {
            return nullptr;
        }

        int mid = (l + r + 1) / 2;
        TreeNode* root = new TreeNode();
        root->left = buildTree(head,l,mid-1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head,mid+1,r);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        int len = getLength(head);
        return buildTree(head,0,len-1);       
    }
};