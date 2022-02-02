#include "iostream"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    int row, col;
    bool dfs(vector<vector<char>>& sad, string word, int i, int j,int k)
    {
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i > row-1 || j > col-1 || sad[i][j] == '\0' || word[k] != sad[i][j])
            return false;
        sad[i][j] = '\0';
        bool res = dfs(sad, word, i-1, j, k+1)||dfs(sad, word, i+1, j, k+1)||dfs(sad, word, i, j-1, k+1)||dfs(sad, word, i, j+1, k+1);
        sad[i][j] = word[k];
        return res;
    }


};

int main()
{

}