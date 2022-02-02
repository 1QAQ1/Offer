#include "iostream"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    //找出sad中所有有value的节点
    void findfather(TreeNode* sad, int value, vector<TreeNode*>& ret)
    {
        if (!sad)
            return;
        if (sad->val == value)
            ret.push_back(sad);
        findfather(sad->left, value, ret);
        findfather(sad->right, value, ret);
    }

    bool find_if_same(TreeNode* a, TreeNode* b)
    {
        if (!b)
            return true;
        if (!a)
            return false;

        bool boola = false;
        bool boolb = false;

        if (a->val == b->val)
        {
            boola = find_if_same(a->left, b->left);
            boolb = find_if_same(a->right, b->right);
        } else{
            return false;
        }

        return boola && boolb;
    }

public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!(A&&B))
            return false;

        vector<TreeNode*> huhu;
        findfather(A, B->val, huhu);

        for (int i = 0; i < huhu.size(); ++i) {
            if (find_if_same(huhu[i], B))
                return true;
        }
        return false;
    }
};

int main()
{
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(0);
    TreeNode* t3 = new TreeNode(1);
    TreeNode* t4 = new TreeNode(-4);
    TreeNode* t5 = new TreeNode(-3);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;

    TreeNode* y1 = new TreeNode(1);
    TreeNode* y2 = new TreeNode(-4);
    y1->left = y2;


    Solution s;

    cout<<boolalpha<<s.isSubStructure(t1, y1);
    return 0;

}