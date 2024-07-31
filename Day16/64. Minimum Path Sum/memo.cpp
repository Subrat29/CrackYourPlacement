#include <bits/stdc++.h>
using namespace std;

// sc: m+n + m*n
// tc: m*n

vector<vector<int>> dp;

int solve(int i, int j, vector<vector<int>> &grid)
{
    if (i == grid.size() || j == grid[0].size())
        return INT_MAX;

    if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return grid[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = solve(i + 1, j, grid);
    int right = solve(i, j + 1, grid);

    dp[i][j] = grid[i][j] + min(down, right);

    return dp[i][j];
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    dp.resize(m, vector<int>(n, -1));

    return solve(0, 0, grid);
}

int main()
{
    return 0;
}