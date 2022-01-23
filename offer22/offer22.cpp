#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return nullptr;
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 1; i < k; ++i) {
            p1 = p1->next;
            if (p1 == nullptr)
                return nullptr;
        }
        while (p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};

int main()
{
    ListNode* sad5 = new ListNode(5);
    ListNode* sad4 = new ListNode(4);
    ListNode* sad3 = new ListNode(3);
    ListNode* sad2 = new ListNode(2);
    ListNode* sad1 = new ListNode(1);
    sad1->next = sad2;
    sad2->next = sad3;
    sad3->next = sad4;
    sad4->next = sad5;

    Solution s;
    ListNode* re = s.getKthFromEnd(sad1, 4);
    cout<<re->val;

    return 0;

}