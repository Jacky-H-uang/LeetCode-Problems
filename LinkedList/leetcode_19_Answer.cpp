/**
 * 
 * 设置双指针 p->next = head    q = head,
 * 删除倒数n时，先让 q向后移动 n 位，然后 p q 一起向后移动 
 * 当 q 为 NULL 时 p->next即为要删除的。
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
 * 删除 p->next
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