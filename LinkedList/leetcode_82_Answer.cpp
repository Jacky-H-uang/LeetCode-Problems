//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中没有重复出现的数字。
//
//示例1:
//输入: 1->2->3->3->4->4->5
//输出: 1->2->5
//
//示例2:
//输入: 1->1->1->2->3
//输出: 2->3
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        head = dummy_head;
        ListNode* moving = head->next;
        bool flag = false;                    //设置一个删除标志
        while(moving)
        {
            if(moving->next && moving->next->val == moving->val)
            {
                ListNode* temp = moving->next;
                moving->next = temp->next;
                delete temp;
                temp = nullptr;
                //moving->next = moving->next->next;
                flag = true;
                continue;
            }
            if(flag)
            {
                dummy_head->next = moving->next;
                delete moving;
                moving = dummy_head;
                flag = false;
            }
            dummy_head = moving;
            moving = moving->next;
        }
        return head->next;
    }
};

int main()
{
    ListNode* q = new ListNode(1);
    q->next = new ListNode(1);
    q->next->next = new ListNode(2);
    q->next->next->next = new ListNode(3);
    q->next->next->next->next = new ListNode(9);
    q->next->next->next->next->next = new ListNode(9);
    Solution s;
    ListNode* r = s.deleteDuplicates(q);
    while(r)
    {
        cout<<r->val<<endl;
        r = r->next;
    }
    system("pause");
    return 0;
}