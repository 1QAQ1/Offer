#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int a = 0;
        int b = nums.size()-1;
        int tem;
        while(a < b)
        {
            while (nums[a]%2 && a < b)
                a++;
            while (!(nums[b]%2) && a < b)
                b--;
            tem = nums[a];
            nums[a] = nums[b];
            nums[b] = tem;
            a++;
            b--;
        }
        return nums;
    }
};

int main()
{
    vector<int> a = {2,1,3,4};
    Solution s;
    vector<int> b = s.exchange(a);
    for (int i = 0; i < b.size(); ++i) {
        cout<<b[i]<<" ";
    }

    return 0;
}