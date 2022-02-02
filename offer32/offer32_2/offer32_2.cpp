#include "iostream"
#include "vector"
#include "deque"

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
        vector<vector<int>> ret;
        if (!root)
            return ret;

        deque<TreeNode*> ptr_deque;
        ptr_deque.push_back(root);

        while(!ptr_deque.empty())
        {
            vector<int> level;
            for (int i = ptr_deque.size(); i > 0; i--) {
                //当前节点放到level vector中
                if (ptr_deque.front())
                    level.push_back(ptr_deque.front()->val);

                //当前节点的左右儿子节点放入队列中
                if (ptr_deque.front())
                {
                    ptr_deque.push_back(ptr_deque.front()->left);
                    ptr_deque.push_back(ptr_deque.front()->right);
                }

                //当前节点从队列中移除
                ptr_deque.pop_front();

                //把这一层的vector放入返回的二层vector中并且清除level vector
                if (i == 1 && !level.empty())
                {
                    ret.push_back(level);
                    level.clear();
                }
            }
        }
        return ret;
    }
};

int main()
{
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
//    TreeNode* t3 = new TreeNode(3);
//    TreeNode* t4 = new TreeNode(4);
//    TreeNode* t5 = new TreeNode(5);
    t1->left = t2;
//    t1->right = t3;
//    t2->left = t4;
//    t2->right = t5;

    Solution s;

    vector<vector<int>> sad = s.levelOrder(t1);

    for (int i = 0; i < sad.size(); ++i) {
        for (int j = 0; j < sad[i].size(); ++j) {
            cout<<sad[i][j]<<" ";
        }
    }
}