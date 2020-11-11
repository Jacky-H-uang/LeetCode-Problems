// 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
//
// 示例1:
//  输入：[1, 2, 3, 3, 2, 1]
//  输出：[1, 2, 3]
//
// 示例2:
//  输入：[1, 1, 1, 1, 2]
//  输出：[1, 2]
//
// 提示：
// 链表长度在[0, 20000]范围内。
// 链表元素在[0, 20000]范围内。
//
// 进阶：
// 如果不得使用临时缓冲区，该怎么解决？



#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// Easy

// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    // 1. 重点在于 未排序的链表
    // 2. 使用 hashtable  --- Yes
    ListNode* removeDuplicateNodes(ListNode* head) 
    {
        if(head == 0)
        {
            return 0;
        }
        unordered_set<int> us;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2!=0)
        {
            if(us.count(p2->val) == 0)
            {
                us.insert(p2->val);
                p1 = p2;
                p2 = p2->next;
            }
            else
            {
                p1->next = p2->next;
                p2 = p2->next;
            }
        }
        return head;
    }
};


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    Solution s;
    ListNode* r = s.removeDuplicateNodes(head);
    while(r!=0)
    {
        cout<<r->val<<"  ";
        r = r->next;
    }

    system("pause");
    return 0;
}