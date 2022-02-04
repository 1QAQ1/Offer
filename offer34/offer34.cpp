#include <vector>
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void sad(TreeNode* root, int target, vector<int> tem, vector<vector<int>>& ret)
    {
        if (!root)
            return;

        if (target == root->val && !root->left && !root->right)
        {
            tem.push_back(root->val);
            ret.push_back(tem);
        } else if (root->left || root->right){
            tem.push_back(root->val);
            sad(root->left, target - root->val, tem, ret);
            sad(root->right, target - root->val, tem, ret);
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> tem;
        vector<vector<int>> ret;

        sad(root, target, tem, ret);
        return ret;
    }
};

int main()
{
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
//    TreeNode* t4 = new TreeNode(4);
//    TreeNode* t5 = new TreeNode(5);
    t1->left = t2;
    t1->right = t3;
//    t2->left = t4;
//    t2->right = t5;

    Solution s;

    vector<vector<int>> sad = s.pathSum(t1, 4);

    for (int i = 0; i < sad.size(); ++i) {
        for (int j = 0; j < sad[0].size(); ++j) {
            cout<<sad[i][j]<<" ";
        }
        cout<<endl;
    }


}