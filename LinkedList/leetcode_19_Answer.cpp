/**
 * 
 * ����˫ָ�� p->next = head    q = head,
 * ɾ������nʱ������ q����ƶ� n λ��Ȼ�� p q һ������ƶ� 
 * �� q Ϊ NULL ʱ p->next��ΪҪɾ���ġ�
 * 
 *    Example:   n = 2
 * 
 *            1 -> 2 -> 3 -> 4 -> 5
 *          p
 *            q
 * 
 *           ...  
 * 
 *            1 -> 2 -> 3 -> 4 -> 5  
 *          p           q
 * 
 *           ...
 * 
 *           1 -> 2 -> 3 -> 4 -> 5
 *                     p            q
 * 
 * ɾ�� p->next
 * 
 * 
 * **/
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = new ListNode(0);
        ListNode* p1 = cur;
        ListNode* p2 = cur;
        cur->next = head;
        for(int i = 0; i < n+1; ++i)      p2 = p2->next;

        while(p2 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;

        return cur->next;
    }
};