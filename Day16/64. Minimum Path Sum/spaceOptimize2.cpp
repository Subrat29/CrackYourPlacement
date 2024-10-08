#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: m*n

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                continue;

            if (i == m - 1)
                grid[i][j] = grid[i][j] + grid[i][j + 1];
            else if (j == n - 1)
                grid[i][j] = grid[i][j] + grid[i + 1][j];
            else
                grid[i][j] = grid[i][j] + min(grid[i + 1][j], grid[i][j + 1]);
        }
    }
    return grid[0][0];
}

int main()
{
    return 0;
}