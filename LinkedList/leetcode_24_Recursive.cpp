#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
	{

        if ( head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
        
    }
};


int main()
{	ListNode* m = new ListNode(1);
	m->next = new ListNode(2);
	m->next->next = new ListNode(3);
	m->next->next->next = new ListNode(4);
	m->next->next->next->next = new ListNode(5);
	m->next->next->next->next->next = new ListNode(6);
	Solution s;
	ListNode* r = s.swapPairs(m);
	for (; r != 0; r = r->next)
	{
		cout << r->val << endl;
	}
    system("pause");
	return 0;
}