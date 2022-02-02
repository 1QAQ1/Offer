#include "iostream"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int sad = 1;
        for (int i = 0; i < 32; i++) {
            if (sad << i & n)
                count++;
        }
        return count;
    }
};

int main()
{

}