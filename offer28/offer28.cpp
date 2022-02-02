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
    bool isSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if (!(root1||root2))
            return true;
        if (!root1)
            return false;
        if (!root2)
            return false;

        if (root1->val == root2->val)
            return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
        else
            return false;
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root, root);
    }
};

int main()
{
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(2);
    TreeNode* t4 = new TreeNode(3);
    TreeNode* t5 = new TreeNode(4);
    TreeNode* t6 = new TreeNode(4);
    TreeNode* t7 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;

    Solution s;

    cout<<boolalpha<<s.isSymmetric(t1);

    return 0;

}