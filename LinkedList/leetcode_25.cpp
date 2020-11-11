//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
// Example:
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5
//
//Note:
//Only constant extra memory is allowed.
//You may not alter the values in the list's nodes, only nodes itself may be changed.


#include<iostream>
using namespace std;
 //Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// Hard

class Solution {
public:
    struct HeadTail
    {
        ListNode *head;
        ListNode *tail;
    };
    HeadTail reverse(ListNode* head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = head;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        HeadTail headTail;
        headTail.head = pre;
        headTail.tail = head;
        return headTail;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == nullptr || head->next == nullptr)
        {
           return head;
        }
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *next = head;
        ListNode *pre_tail = nullptr;
        ListNode *newHead = head;
        int count = 0;
        while(head)
        {
            count++;
            next = head->next;
            if(count == k)
            {
                head->next = nullptr;
                HeadTail headTail = reverse(newHead);
                if(pre_tail)
                {
                    pre_tail->next = headTail.head;
                }
                else
                {
                    dummyHead->next = headTail.head;
                }
                headTail.tail->next = next;
                pre_tail = headTail.tail;
                newHead = next;
                count = 0;
            }
            head = next;
        }
        return dummyHead->next;
    }

};