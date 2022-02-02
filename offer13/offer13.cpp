#include "iostream"

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int step = 0;
        vector<vector<bool>>Themark(m, vector<bool>(n, false));
        return dfs(step, m, n, k, 0, 0, Themark);
    }

    int dfs(int &step, int m, int n, int k, int x, int y, vector<vector<bool>>& mark)
    {
        if (x >= m||y >= n||k < getsum(x, y)||mark[x][y])
            return 0;
        step++;
        mark[x][y] = true;
        dfs(step, m, n, k, x+1, y, mark);
        dfs(step, m, n, k, x, y+1, mark);
        return step;
    }

    static int getsum(int x, int y)
    {
        int sum = 0;
        while (x != 0)
        {
            sum += (x % 10);
            x /= 10;
        }
        while (y != 0)
        {
            sum += (y % 10);
            y /= 10;
        }
        return sum;
    }


};

int main()
{

}