//          501. 二叉搜索树中的众数
//
// 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
// 假定 BST 有如下定义：
// 结点左子树中所含结点的值小于等于当前结点的值
// 结点右子树中所含结点的值大于等于当前结点的值
// 左子树和右子树都是二叉搜索树
//
// 例如：
// 给定 BST [1,null,2,2],
//    1
//     \
//      2
//     /
//    2
// 返回[2].
//
// 提示：如果众数超过1个，不需考虑输出顺序
// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）


#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Easy

class Solution {
public:
    struct node
    {
        int e;
        int t;

    };
    struct cmp
    {
        bool operator()(node n1, node n2)
        {
            return n1.t < n2.t;
        }
    };
    
    vector<int> ans;
    unordered_map<int,int> cnt;
    void helper(TreeNode* r)
    {
        if(r == nullptr)
        {
            return;
        }
        cnt[r->val]++;
        helper(r->left);
        helper(r->right);
    }
    vector<int> findMode(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return ans;
        }
        helper(root);
        priority_queue<node,vector<node>,cmp> pq;
        for(unordered_map<int,int> :: iterator it = cnt.begin(); it != cnt.end(); ++it)
        {
            node n;
            n.e = it->first;
            n.t = it->second;
            pq.push(n);
        }
        node x = pq.top();
        pq.pop();
        ans.push_back(x.e);
        while(!pq.empty())
        {
            node tmp = pq.top();
            pq.pop();
            if(x.t > tmp.t)
            {
                break;
            }
            else
            {
                ans.push_back(tmp.e);
            }
        }

        return ans;
    }
};