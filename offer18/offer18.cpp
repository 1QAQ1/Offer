#include "iostream"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val)
        {
            head = head->next;
            return head;
        }
        ListNode* tem = head;
        while (tem->next->val != val)
        {
            tem = tem->next;
        }
        ListNode* del = tem->next;
        tem->next = tem->next->next;
        delete del;
        return head;
    }
};

int main()
{
    //这题改的我都懒得写测试，恶心
}