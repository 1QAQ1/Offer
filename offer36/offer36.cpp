#include "iostream"
#include "vector"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
private:
    void findvec(Node* root, vector<Node*>& vec)
    {
        if (root->left)
            findvec(root->left,vec);

        if (root)
            vec.push_back(root);
        else
            return;

        if (root->right)
            findvec(root->right, vec);

    }

public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
        {
            root->left = root;
            root->right = root;
            return root;
        }
        vector<Node*> trvec;
        findvec(root, trvec);

        for (int i = 1; i < trvec.size()-1; ++i) {
            trvec[i]->left = trvec[i-1];
            trvec[i]->right = trvec[i+1];
        }
        trvec[0]->left = trvec[trvec.size()-1];
        trvec[0]->right = trvec[1];
        trvec[trvec.size()-1]->left = trvec[trvec.size()-2];
        trvec[trvec.size()-1]->right = trvec[0];

        return trvec[0];
    }

    void printree(Node* root)
    {
        if (root->left)
            printree(root->left);

        if (root)
            cout<<root->val<<" ";
        else
            return;

        if (root->right)
            printree(root->right);
    }

};



int main()
{
    Node t5(5);
    Node t4(4);
    Node t2(2, &t4, &t5);
    Node t3(3);
    Node t1(1, &t2, &t3);



    Solution s;

    s.printree(&t1);
    cout<<endl;

    Node* root = s.treeToDoublyList(&t1);

    for (int i = 0; i < 5; ++i) {
        cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<endl;
        root = root->right;
    }


}