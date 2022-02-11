#include "iostream"
#include "string"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//破防了xdm
class Codec {
private:
    void treetostr(TreeNode* root, string& s)
    {
        if (!root)
        {
            s.push_back('!');
            return;
        }

        s.push_back(root->val);
        treetostr(root->left,s);
        treetostr(root->right, s);
    }

    void str_to_tree(TreeNode* root, string s, int& cur)
    {
        cur++;
        if (s[cur-1] != '!' && !cur == s.size())
        {
            root->val = (int)s[cur-1];
            cout<<s[cur-1]<<" ";
        }else
        {
            return;
        }

        TreeNode left;
        TreeNode right;
        root->left = &left;
        root->right = &right;


        str_to_tree(&left, s, cur);
        str_to_tree(&right, s, cur);
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string sad;

        treetostr(root, sad);
        return sad;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* ans;
        int cur = 0;
        str_to_tree(ans, data, cur);
        return ans;
    }

    void showtree(TreeNode* root)
    {
        if (root)
            cout<<root->val<<" ";
        else
            return;
        if (root->left)
            showtree(root->left);
        if (root->right)
            showtree(root->right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    /*
          1
        /   \
       2     3          1 2 ! ! 3 4 ! ! 5 ! !
           /  \
          4    5        tree
    */
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode* root = &t1;

    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t4;
    t3.right = &t5;

    Codec s;

    s.showtree(root);
    cout<<endl;

    string tree_str = s.serialize(root);

    for (int i = 0; i < tree_str.size(); ++i) {
        cout<<tree_str[i]<<" ";
    }

    TreeNode* sad = s.deserialize(tree_str);

    s.showtree(sad);
}
