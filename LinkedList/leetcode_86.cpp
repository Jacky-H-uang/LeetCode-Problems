// ����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

// ��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�

// ʾ��:

// ����: head = 1->4->3->2->5->2, x = 3
// ���: 1->2->2->4->3->5

#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *p = head;
        ListNode *q = head;
        if(head == 0)
        {
            return 0;
        }
        while(p!=0)                         //�ҵ��ٽ��
        {
            if(p->val >= x)
            {
                q = p;
                break;
            }
            dummy_head->next = p;
            p = p->next;
        }
        if(dummy_head->next->next==0)
        {
            return head;
        }
        ListNode *t1 = q;
        ListNode *t2 = q;
        while(t2)
        {
            if(t2->val < x)
            {
                if(dummy_head->next == q)
                {
                    t1->next = t2->next;
                    t2->next = q;
                    dummy_head->next = t2;
                    t2 = t1->next;
                    head = dummy_head->next;
                    continue;
                }
                t1->next = t2->next;
                t2->next = q;
                dummy_head->next->next = t2;
                dummy_head->next = t2;
                t2 = t1->next;
                
                continue;
            }
            t1 = t2;
            t2 = t2->next;
        }
        return head;
    }
};

int main()
{	ListNode* m = new ListNode(2);
    m->next = new ListNode(1);
    //m->next->next = new ListNode(1);
    // m->next = new ListNode(4);
    // m->next->next = new ListNode(3);
    // m->next->next->next = new ListNode(2);
    // m->next->next->next->next = new ListNode(5);
    // m->next->next->next->next->next = new ListNode(2);
    Solution s;
    ListNode* r = s.partition(m,1);
    for (; r != 0; r = r->next)
    {
        cout << r->val << endl;
    }
    system("pause");
    return 0;
}