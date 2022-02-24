#include "iostream"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    map<int, int> sad;

    int majorityElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (sad.count(nums[i]) == 0)
            {
                sad[nums[i]] = 1;
            } else{
                sad[nums[i]] = sad[nums[i]] + 1;
                if (sad.at(nums[i]) > nums.size()/2)
                    return nums[i];
            }
        }
        if (sad.size() == 1)
            return nums[0];
        return 0;
    }
};

int main()
{
    vector<int>ve;
    ve.push_back(1);
    ve.push_back(2);
    ve.push_back(2);
    ve.push_back(2);
    ve.push_back(2);
    ve.push_back(4);

    Solution s;
    int i = s.majorityElement(ve);

    cout<<i;
    return 0;
}