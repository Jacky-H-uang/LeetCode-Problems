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


// 对于 BST 的时候的特殊遍历
class Solution {
public:
    int base, count, maxCount;
    vector<int> answer;

    void update(int x) 
    {
        if (x == base) 
        {
            ++count;
        } 
        else 
        {
            count = 1;
            base = x;
        }
        if (count == maxCount) 
        {
            answer.push_back(base);
        }
        if (count > maxCount) 
        {
            maxCount = count;
            answer = vector<int> {base};
        }
    }

    vector<int> findMode(TreeNode* root) 
    {
        TreeNode *cur = root, *pre = nullptr;
        while (cur) 
        {
            if (!cur->left) 
            {
                update(cur->val);
                cur = cur->right;
                continue;
            }
            pre = cur->left;
            
            while (pre->right && pre->right != cur) 
            {
                pre = pre->right;
            }

            if (!pre->right) 
            {
                pre->right = cur;
                cur = cur->left;
            }
            else 
            {
                pre->right = nullptr;
                update(cur->val);
                cur = cur->right;
            }
        }
        return answer;
    }
};