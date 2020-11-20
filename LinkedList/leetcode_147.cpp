#include<bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Medium

class Solution {
public:
    // 链表的插入排序
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre;
        while(head != NULL && head->next != NULL) {
            if(head->val <= head->next->val)
            {
                head = head->next;
                continue;
            }

            pre = dummy;

            while(pre->next->val < head->next->val)     pre = pre->next;
            ListNode* cur = head->next;
            head->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        }

        return dummy->next;
    }
};