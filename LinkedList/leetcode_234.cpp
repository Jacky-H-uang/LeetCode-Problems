//                      234. Palindrome Linked List
//
// Given a singly linked list, determine if it is a palindrome.
//
// Example 1:
// Input: 1->2
// Output: false
//
// Example 2:
// Input: 1->2->2->1
// Output: true
//
//
// Follow up:
// Could you do it in O(n) time and O(1) space?

#include<bits/stdc++.h>
using namespace std;

// Easy

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)       return true;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转后面的链表
        ListNode* pre = NULL;
        ListNode* cur = slow;
        while(cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        // 双指针来判定
        ListNode* p1 = head;
        ListNode* p2 = pre;
        while(p1 != NULL && p2 != NULL && p1 != p2) {
            if(p1->val != p2->val)      return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};