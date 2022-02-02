#include "iostream"

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3)
            return n-1;
        long long sum=1;
        while(n>4)
        {
            sum=sum*3%1000000007;
            n-=3;
        }
        return sum*n%1000000007;
    }
};

int main()
{

}
