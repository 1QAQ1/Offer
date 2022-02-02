#include "iostream"

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n == 0||n == 1)
            return 1;
        long long a = 1;
        long long b = 1;
        long long c = 0;
        for (int i = 0; i < n - 1; i++) {
            c = a + b;
            a = b;
            c %= 1000000007;
            b = c;
        }
        return c;
    }
};

int main()
{

}