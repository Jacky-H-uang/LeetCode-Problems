// ���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㣬�㽫ֻ������Ҫ��ɾ���Ľڵ㡣
//
// ����һ������ --?head =?[4,5,1,9]�������Ա�ʾΪ:
//      4 -> 5 -> 1 -> 9
//
// ʾ�� 1:
// ����: head = [4,5,1,9], node = 5
// ���: [4,1,9]
// ����: ������������ֵΪ?5?�ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
//
// ʾ�� 2:
// ����: head = [4,5,1,9], node = 1
// ���: [4,5,9]
// ����: ������������ֵΪ?1?�ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.
//
// ˵��:
// �������ٰ��������ڵ㡣
// ���������нڵ��ֵ����Ψһ�ġ�
// �����Ľڵ�Ϊ��ĩβ�ڵ㲢��һ���������е�һ����Ч�ڵ㡣
// ��Ҫ����ĺ����з����κν����

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
    void deleteNode(ListNode* node) 
    {
        ListNode *p = node;
        while(node->next)
        {
            node->val = node->next->val;
            p = node;
            node = node->next;
        }
        p->next = NULL;
        node = NULL;
    }
};


int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    Solution s;
    s.deleteNode(head->next->next);
    while (head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    system("pause");
    return 0;
}