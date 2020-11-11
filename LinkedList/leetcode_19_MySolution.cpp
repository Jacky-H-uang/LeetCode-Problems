#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* h1= head;
        ListNode* h2 = head;
        int count = 0;
        while (p)
        {
            p=p->next;
            count++;
        }
        int tmp = count-n;
        for(int i=0;i<tmp;i++)
        {
            h1=h2;
            h2=h2->next;
        }
        if(h2 == head)
        {
            head = h2->next;
            h2->next =0; 
        }
        if(h2 == 0)
        {
            h1->next = 0;
            delete h2;
            return head;
        }
        h1->next = h2->next;
        h2->next = 0;
        delete h2;
        return head;
    }
};


int main()
{
    ListNode* p =new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* m = s.removeNthFromEnd(p,1);
    cout<<m->val<<endl;
    system("pause");
    return 0;
}