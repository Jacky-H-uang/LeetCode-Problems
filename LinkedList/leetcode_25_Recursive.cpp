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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


// Hard

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre=head;
        int count=0;
        while(pre!=NULL&&count<k)
        {
            pre=pre->next;
            count++;
        } //退出循环后pre指向第k+1个节点

        if(count==k) 
        {
            pre=reverseKGroup(pre,k);
            while(count>0)
            { 
                /* 
                 * head指向本次循环反转指向的节点
                 * temp指向下次循环反转指向的节点
                 */
                ListNode* temp = head->next; 
                head->next = pre;
                pre = head;
                head = temp;
                count--;
            }
            head=pre;
        }
        return head;
    }
};