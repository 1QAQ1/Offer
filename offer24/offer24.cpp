#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//内存消耗超大，就这
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;

        ListNode* now = head;
        ListNode* nex = head->next;
        ListNode* copynex = nex;
        ListNode* newhead = nex;

        if(nex->next)
            newhead = reverseList(nex);
        nex->next = now;
        now->next = nullptr;
        //找到尾节点并遗传下来
        if (!nex->next)
            return copynex;
        return newhead;
    }
};

int main()
{
    Solution s;
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    for (ListNode* head = p1; head; head = head->next)
    {
        cout<<head->val<<" ";
    }
    ListNode* newp1 = s.reverseList(p1);
    for (ListNode* head = newp1; head; head = head->next)
    {
        cout<<head->val<<" ";
    }
    return 0;
}