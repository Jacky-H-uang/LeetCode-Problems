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



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(0);
        ListNode* ans = cur;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry > 0)
        {
            int t1 = l1 == nullptr? 0 : l1->val;
            int t2 = l2 == nullptr? 0 : l2->val;
            int t = (t1 + t2 + carry) % 10;
            carry = (t1 + t2 + carry) / 10;
            cur->next = new ListNode(t);
            cur = cur->next;
            l1 = l1 == nullptr? nullptr : l1->next;
            l2 = l2 == nullptr? nullptr : l2->next;
        }

        return ans->next;
    }
};