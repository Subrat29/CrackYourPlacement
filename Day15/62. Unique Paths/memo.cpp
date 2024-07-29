#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

vector<vector<int>> dp;

int solve(int m, int n, int i, int j)
{
    if (i >= m || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    // Down
    int down = solve(m, n, i + 1, j);
    // Right
    int right = solve(m, n, i, j + 1);

    dp[i][j] = down + right;
    return down + right;
}

int uniquePaths(int m, int n)
{
    dp.resize(m, vector<int>(n, -1));
    return solve(m, n, 0, 0);
}

int main()
{
    cout << uniquePaths(3, 7);
    return 0;
}