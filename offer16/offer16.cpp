#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        int tag = 0;
        if (x == 0)
            return 0;
        if (x == 1)
            return x;
        if (n == 1)
            return x;
        if (n == 0)
            return 1;
        long b = n;
        if (b < 0) {
            tag = 1;
            b *= -1;
        }
        double ret = 0;
        ret = myPow(x, b >> 1);
        if (b % 2) {
            ret = ret * ret * x;
        } else {
            ret = ret * ret;
        }
        if (tag)
            return 1 / ret;
        else
            return ret;
    }
};

int main() {
    cout << "sad" << endl;
    Solution sad;
    cout << sad.myPow(2.00000, 10);

    return 0;
}
