#include "iostream"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* head = nullptr;
        if (l1->val < l2->val)
        {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }else{
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(5);
    ListNode* p4 = new ListNode(6);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    ListNode* q1 = new ListNode(2);
    ListNode* q2 = new ListNode(4);
    ListNode* q3 = new ListNode(6);
    ListNode* q4 = new ListNode(7);
    q1->next = q2;
    q2->next = q3;
    q3->next = q4;

    ListNode* pq = s.mergeTwoLists(p1, q1);
    for (ListNode* head = pq; head; head = head->next)
    {
        cout<<head->val<<" ";
    }

}