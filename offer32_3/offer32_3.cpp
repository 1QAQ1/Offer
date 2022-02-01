#include "iostream"
#include "vector"
#include "deque"
#include "stack"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> ptr_deque;
        vector<int> level;
        vector<vector<int>> ans;

        if (!root)
            return ans;

        ptr_deque.push_back(root);
        bool front = true;

        while (!ptr_deque.empty())
        {
            for (int i = ptr_deque.size(); i > 0; --i)
            {
                //决定正向遍历还是逆向遍历
                if (front)
                {
                    //当前节点加入到level vector中
                    if (ptr_deque.front())
                        level.push_back(ptr_deque.front()->val);
                    //当前节点左右儿子节点放入ptr_deque，并删除当前节点
                    if (ptr_deque.front())
                    {
                        ptr_deque.push_back(ptr_deque.front()->left);
                        ptr_deque.push_back(ptr_deque.front()->right);
                    }
                    ptr_deque.pop_front();
                }else{
                    if (ptr_deque.back())
                        level.push_back(ptr_deque.back()->val);
                    if (ptr_deque.back())
                    {
                        ptr_deque.push_front(ptr_deque.back()->right);
                        ptr_deque.push_front(ptr_deque.back()->left);
                    }
                    ptr_deque.pop_back();
                }
                //把这一层的数据传入到ans中，并清空level vector
                if (i == 1)
                {
                    if (!level.empty())
                        ans.push_back(level);
                    level.clear();
                    front ? front = false : front = true;
                }
            }
        }
        return ans;

    }
};

int main()
{
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;

    Solution s;

    vector<vector<int>> sad = s.levelOrder(t1);

    for (int i = 0; i < sad.size(); ++i) {
        for (int j = 0; j < sad[i].size(); ++j) {
            cout<<sad[i][j]<<" ";
        }
    }
}