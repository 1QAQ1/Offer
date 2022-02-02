#include"iostream"

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        vector<int>sad{0, 0, 2, 3};


        for (int i = 4; i < n + 1; ++i) {
            int maxsad = 0;
            for (int j = 2; j < i/2+1; ++j) {
                if (max(sad[j]*(sad[i-j]), j*(i-j)) > maxsad)
                    maxsad = max(sad[j]*(sad[i-j]), j*(i-j));
            }
            sad.push_back(maxsad);
        }
        return sad[n];
    }
};

int main()
{

}