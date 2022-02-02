#include "iostream"
#include "vector"
#include "iterator"

using namespace std;

class Solution {
private:
    bool vecaddone(char* sad, int n)
    {
        if (n == 0)
            return false;
        if (sad[n] != '9')
        {
            sad[n] = sad[n] + 1;
        }else{
            sad[n] = '0';
            if (!vecaddone(sad, n-1))
                return false;
        }
        return true;
    }

    void addintovec(vector<int>& ret, char* sad, int n)
    {
        long long temp = 0;
        for (int i = 1; i < n+1; i++) {
            temp = temp*10 + sad[i] - '0';
        }
        ret.push_back(temp);
    }

public:
    vector<int> printNumbers(int n) {
        char tem[n+1];
        for (int i = 0; i < n+1; ++i) {
            tem[i] = '0';
        }
        vector<int> ret;

        while (vecaddone(tem, n)) {
            addintovec(ret, tem, n);
        }
        return ret;
    }
};
 
int main()
{
    Solution s;
    vector<int> a = s.printNumbers(2);
//    for (vector<int>::iterator iter = a.begin(); iter != a.end() ; iter++) {
//        cout<<(*iter)<<endl;
//    }
    for (int i = 0; i < a.size(); ++i) {
        cout<<a[i]<<"  ";
    }

    return 0;
}
