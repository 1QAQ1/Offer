#include "iostream"

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long start = 1;
        int digit = 1;
        long long count = 9;
        while(n>count){
            n -=count;
            start *= 10;
            digit ++;
            count = start*digit*9;
        }
        int num = start +(n-1)/digit;
        string s = to_string(num);
        return s[(n-1)%digit] - '0';
    }
};

int main()
{
    Solution s;
    cout<<s.findNthDigit(5);
    return 0;
}

//位数n   数字数量    位数数量
//1         9
//2         90
//3         900
//4         9000