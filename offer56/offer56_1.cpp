#include "iostream"
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        set<int> sad;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = sad.find(nums[i]);
            if (it == sad.end())
                sad.insert(nums[i]);
            else
                sad.erase(it);
        }
        ans.assign(sad.begin(), sad.end());
        return ans;
    }
};

int main()
{

}