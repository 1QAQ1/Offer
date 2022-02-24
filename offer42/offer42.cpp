#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int ans = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i-1] + nums[i] >= nums[i])
                dp.push_back(dp[i-1] + nums[i]);
            else
                dp.push_back(nums[i]);

            if (ans < dp[i])
                ans = dp[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> sad = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int a = s.maxSubArray(sad);

    cout<<a;

    return 0;
}