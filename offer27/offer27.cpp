#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return nullptr;
        if (!(root->left||root->right))
            return root;

        TreeNode* tem = root->left;
        root->left = root->right;
        root->right = tem;

        if (root->right)
            mirrorTree(root->right);
        if (root->left)
            mirrorTree(root->left);

        return root;
    }
};

static void printree(TreeNode* root)
{
    if (!root)
    {
        cout<<"null ";
        return;
    }
    cout<<root->val<<" ";
    if (!(root->left||root->right))
        return;
    printree(root->left);
    printree(root->right);
}

int main()
{
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
//  TreeNode* t3 = new TreeNode(1);
    TreeNode* t4 = new TreeNode(1);
//  TreeNode* t5 = new TreeNode(-3);
    t1->left = t2;
//  t1->right = t3;
    t2->left = t4;
//  t2->right = t5;

    printree(t1);

    Solution s;

    TreeNode* sad = s.mirrorTree(t1);

    cout<<endl;

    printree(sad);

}