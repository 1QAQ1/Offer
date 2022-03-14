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
    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;
        //左右子树深度
        int leftdepth = 0;
        int rightdepth = 0;

        //检查并返回子树深度
        if (root->left)
            leftdepth = dfs(root->left);
        if (root->right)
            rightdepth = dfs(root->right);

        //检查子树是不是平衡二叉树
        if (leftdepth == -1 || rightdepth == -1)
            return -1;

        //检查当前树是否是平衡二叉树
        if (abs(leftdepth - rightdepth) > 1)
            return -1;
        else
            return max(leftdepth + 1, rightdepth + 1);
    }

    bool isBalanced(TreeNode* root) {
        if (dfs(root) == -1)
            return false;
        else
            return true;
    }
};

int main()
{
    //      3
    //     / \
    //    9   20
    //        / \
    //       15  7

    TreeNode t1(3);
    TreeNode t2(9);
    TreeNode t3(20);
    TreeNode t6(15);
    TreeNode t7(7);

    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t6;
    t3.right = &t7;
    TreeNode* head = &t1;

    Solution s;
    cout<<boolalpha<<s.isBalanced(head);


}