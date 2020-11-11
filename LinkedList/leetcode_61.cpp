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
    ListNode* rotateRight(ListNode* head, int k) {
        for(int i=0;i<k;i++)
        {
            ListNode *p = head;
            ListNode *q = head;
            while (p->next != 0)
            {
                q = p;
                p = p->next;
            }
            p->next = head;
            q->next = 0;
            head = p;
        }
        return head;
    }
};

int main()
{	ListNode* m = new ListNode(0);
    //m->next = new ListNode(1);
    //m->next->next = new ListNode(2);
    //m->next->next->next = new ListNode(4);
    //m->next->next->next->next = new ListNode(5);
    //m->next->next->next->next->next = new ListNode(6);
    Solution s;
    ListNode* r = s.rotateRight(m,2);
    for (; r != 0; r = r->next)
    {
        cout << r->val << endl;
    }
    system("pause");
    return 0;
}