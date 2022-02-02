#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size())
            return false;

        int pushed_i = 0;
        stack<int> sad;

        for (int i = 0; i < popped.size(); ++i)
        {
            while (sad.empty() || sad.top() != popped[i])
            {
                if (pushed_i >= pushed.size())
                    return false;
                sad.push(pushed[pushed_i++]);

            }
            sad.pop();
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> vec1 = {1,2,3,4,5};
    vector<int> vec2 = {4,3,5,1,2};
    cout<<boolalpha<<s.validateStackSequences(vec1, vec2);
}