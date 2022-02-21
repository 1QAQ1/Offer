#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

class Solution {
public:
    vector<string> ans;
    string add;
    unordered_set<string> anscop;

    void sad(string s, bool vis[])
    {
        if (add.length() == s.size())
        {
            anscop.insert(add);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (!vis[i])
            {
                //处理节点
                add += s[i];
                vis[i] = true;
                //递归
                sad(s, vis);
                //回溯
                add = add.substr(0, add.length()-1);
                vis[i] = false;
            } else{
                continue;
            }
        }
    }

    bool ifnothas(string s)
    {
        if (ans.empty())
            return true;
        for (auto it = ans.begin(); it != ans.end(); it++) {
            if (*it == s)
                return false;
        }
        return true;
    }

    vector<string> permutation(string s) {
        bool* vis = new bool[s.size()]();
        if (s.empty())
            return ans;
        else
            sad(s, vis);
        ans.assign(anscop.begin(), anscop.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> sad;
    sad = s.permutation("sa");

    for (auto it = sad.begin(); it != sad.end() ; it++) {
        cout<<*it<<" ";
    }

    return 0;
}