//                              143. Reorder List
//
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
// Given 1->2->3->4, reorder it to 1->4->2->3.
//
// Example 2:
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 利用栈来存储节点
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* tmp = head;
        stack<ListNode*> s;
        while(tmp != NULL) {
            s.push(tmp);
            tmp = tmp->next;
        }
        
        ListNode* cur = head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        int size = (s.size() + 1) / 2;

        while(size--) {
            dummy->next = cur;
            cur = cur->next;
            dummy = dummy->next;
            dummy->next = NULL;
            ListNode* x = s.top();
            s.pop(); 
            dummy->next = x;
            dummy = dummy->next;
            dummy->next = NULL;
        }
    }
};
