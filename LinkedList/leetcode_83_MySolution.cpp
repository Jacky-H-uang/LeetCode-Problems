/**
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 *
 *示例 1:
 *
 *输入: 1->1->2
 *输出: 1->2
 *
 *示例 2:
 *
*输入: 1->1->2->3->3
 *输出: 1->2->3
 **/
#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
            if(head == 0)
            {
                return head;
            }
            ListNode* p = new ListNode(0);
            p->next = head;
            ListNode* result = p;
            while(head->next!=0)
            {
                if(p->next->val == head->next->val)
                {
                    head = head->next;
                    p->next->next=0;
                    delete p->next;
                    p->next = head;
                }
                else
                {
                    head = head->next;
                    p = p->next;
                }
            }
            return result->next;
    }
};

int main()
{
    ListNode* q = new ListNode(1);
    q->next = new ListNode(1);
    q->next->next = new ListNode(2);
    Solution s;
    ListNode* r = s.deleteDuplicates(q);
    while(r)
    {
        cout<<r->val<<endl;
        r = r->next;
    }
    return 0;
}

