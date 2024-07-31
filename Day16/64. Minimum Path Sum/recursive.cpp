#include <bits/stdc++.h>
using namespace std;

// sc: m+n
// tc: 2^(m+n)

int solve(int i, int j, vector<vector<int>> &grid)
{
    if (i == grid.size() || j == grid[0].size())
        return INT_MAX;

    if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return grid[i][j];

    int down = solve(i + 1, j, grid);
    int right = solve(i, j + 1, grid);
    return grid[i][j] + min(down, right);
}

int minPathSum(vector<vector<int>> &grid)
{
    return solve(0, 0, grid);
}

int main()
{
    return 0;
}