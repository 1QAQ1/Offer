#include "iostream"
#include "vector"

using namespace std;

//所以我为什么不传角标，穿迭代器？麻了
class Solution {
private:
    bool sad_verify(vector<int>::iterator fir, vector<int>::iterator sec, vector<int>& postorder)
    {
        if (sec - fir == 1 || sec - fir == 2 || sec - fir == 0)
            return true;

        int rootval = *(sec - 1);
        int point_of_sectree;

        for (vector<int>::iterator it = fir;  it != sec ; it++) {
            if (*it >= rootval)
            {
                point_of_sectree = distance(postorder.begin(), it);
                break;
            }
        }

        for(vector<int>::iterator it = postorder.begin()+point_of_sectree; it != sec; it++)
        {
            if (*it < rootval)
                return false;
        }

        return sad_verify(fir, postorder.begin()+point_of_sectree, postorder) && sad_verify(postorder.begin()+point_of_sectree, sec-1, postorder);

    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return sad_verify(postorder.begin(), postorder.end(), postorder);
    }
};

int main()
{
    vector<int> sad = {1, 2, 3, 4, 5};
    Solution s;

    cout<<boolalpha<<s.verifyPostorder(sad);
}