//合并?k?个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例:
//
//输入:
//[
//? 1->4->5,
//? 1->3->4,
//? 2->6
//]
//输出: 1->1->2->3->4->4->5->6
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    struct cmp
    {  //对新的数据类型的<进行重写
        bool operator()(ListNode *a,ListNode *b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode* ,vector<ListNode*> , cmp> heapk;
        for(auto p:lists)
        {
            if(p!=NULL)
            {
                heapk.push(p);
            }
        }
        ListNode *pHead = new ListNode(-1);
        ListNode *pCur = pHead;
        while(!heapk.empty())
        {
            ListNode *top = heapk.top();heapk.pop();
            pCur->next = top;
            pCur = pCur->next;
            if(top->next!=NULL)
            {
                heapk.push(top->next);
            }
        }
        pCur = pHead->next;
        delete pHead;
        return pCur;
    }
};

