//Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *p = head;
		ListNode *q = head;
		ListNode *l;
		if (head->next != 0)
		{
			head = head->next;
		}
		while (q->next != 0)
		{
			q = q->next;
			p->next = q->next;
			q->next = p;
			if (p->next == 0)
			{
				return head;
			}
			l = q->next;
			p = p->next;
			q = p;
			if (q->next != 0)
			{
				l->next = p->next;
			}
		}
		return head;
	}
};

int main()
{	ListNode* m = new ListNode(1);
	//m->next = new ListNode(2);
	//m->next->next = new ListNode(3);
	//m->next->next->next = new ListNode(4);
	//m->next->next->next->next = new ListNode(5);
	//m->next->next->next->next->next = new ListNode(6);
	Solution s;
	ListNode* r = s.swapPairs(m);
	for (; r != 0; r = r->next)
	{
		cout << r->val << endl;
	}
    system("pause");
	return 0;
}