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
#include<tuple>
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
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) 
    {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) 
        {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) 
        {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i)
            {
                tail = tail->next;
                if (!tail) 
                {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            tie(head, tail) = myReverse(head, tail);            //tie 把括号里面的东西整合成元组
                                                                // 这里是 C++17 的写法，也可以写成
                                                                // pair<ListNode*, ListNode*> result = myReverse(head, tail);
                                                                // head = result.first;
                                                                // tail = result.second;
                                                                // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};