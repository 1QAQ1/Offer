#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    void quick(vector<int>& sad, int l, int r, int k)
    {
        if (r == l)
            return;

        int i = l;
        int j = r;

        while (i < j)
        {
            while (sad[j] >= sad[l] && i < j)
                j--;
            while (sad[l] >= sad[i] && i < j)
                i++;

            swap(sad[i], sad[j]);
        }

        swap(sad[l], sad[i]);

        if (i == k)
            return;
        if (i > k)
            quick(sad, l, i-1, k);
        if (i < k)
                quick(sad, i+1, r, k);
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> cop = arr;
        quick(cop, 0, arr.size()-1, k);
        vector<int> aaa(cop.begin(), cop.begin()+k);

        return aaa;
    }
};

int main()
{
    Solution s;
    vector<int> a = {3,5,1,2,5};
    vector<int> out = s.getLeastNumbers(a, 3);

    for (int i = 0; i < out.size(); ++i) {
        cout<<out[i]<<" ";
    }

    return 0;
}