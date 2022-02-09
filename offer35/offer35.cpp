#include "iostream"

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        Node* sadptr = head;
        Node* ans;
        //把123变为112233
        while (sadptr)
        {
            Node* tem = new Node(0);
            tem->next = sadptr->next;
            tem->val = sadptr->val;
            tem->random = nullptr;
            sadptr->next = tem;
            sadptr = tem->next;
        }

        sadptr = head;
        Node* retptr = sadptr->next;

        //random复制过来
        while (true)
        {
            if (sadptr->random)
                retptr->random = sadptr->random->next;

            if (!sadptr->next->next)
                break;

            sadptr = sadptr->next->next;
            retptr = sadptr->next;
        }

        sadptr = head;
        retptr = sadptr->next;
        ans = retptr;

        //112233变为123
        while (true)
        {
            sadptr->next = sadptr->next->next;
            sadptr = sadptr->next;

            if (retptr->next)
                retptr->next = retptr->next->next;
            retptr = retptr->next;

            if (!retptr || !retptr->next)
            {
                if (sadptr)
                    sadptr->next = nullptr;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    Node* n1 = new Node(-1);
//    Node* n2 = new Node(2);
//    Node* n3 = new Node(3);
//    Node* n4 = new Node(4);
    n1->next = nullptr;
//    n2->next = n3;
//    n3->next = n4;
//    n1->random = nullptr;
//    n2->random = n4;
//    n3->random = n1;
//    n4->random = n2;

    Node* sad = n1;

    while(sad)
    {
        cout<<"val:"<<sad->val<<"  rendomval:";
        if (sad->random)
            cout<<sad->random->val;
        cout<<endl;
        sad = sad->next;
    }

    Solution s;
    sad = s.copyRandomList(n1);

    cout<<endl;

    while(sad)
    {
        cout<<"val:"<<sad->val<<"  rendomval:";
        if (sad->random)
            cout<<sad->random->val;
        cout<<endl;
        sad = sad->next;
    }



}

