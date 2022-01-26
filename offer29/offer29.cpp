#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    void spiralOrder(vector<vector<int>>& matrix, vector<int>& ret, int row, int column, int start)
    {
        if (row <= 2*start || column <= 2*start)
            return;
        for (int i = start; i < column-start; ++i) {
            ret.push_back(matrix[start][i]);
        }
        for (int i = start+1; i < row-start; ++i) {
            ret.push_back(matrix[i][column-start-1]);
        }
        if (row - 2*start - 1)
        {
            for (int i = column-start-2; i >= start; --i) {
                ret.push_back(matrix[row-1-start][i]);
            }
        }
        if (column - 2*start -1)
        {
            for (int i = row-start-2; i > start; --i) {
                ret.push_back(matrix[i][start]);
            }
        }
        spiralOrder(matrix, ret, row, column, start+1);
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty())
            return ret;

        int row = matrix.size();
        int column = matrix[0].size();

        spiralOrder(matrix, ret, row, column, 0);
        return ret;
    }
};

int main()
{
    vector<vector<int>> sad(1, vector<int>(4));

    sad[0][0] = 1;
    sad[0][1] = 2;
    sad[0][2] = 3;
    sad[0][3] = 4;
//    sad[1][0] = 5;
//    sad[1][1] = 6;
//    sad[1][2] = 7;
//    sad[1][3] = 8;
//    sad[2][0] = 9;
//    sad[2][1] = 10;
//    sad[2][2] = 11;
//    sad[2][3] = 12;

    Solution s;

    vector<int> ans = s.spiralOrder(sad);

    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<" ";
    }
    return 0;

}
