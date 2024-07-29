#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

// Bottom up Approach

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int down = dp[i + 1][j];
            int right = dp[i][j + 1];
            dp[i][j] += down + right;
        }
    }
    return dp[0][0];
}

int main()
{
    cout << uniquePaths(3, 2);
    return 0;
}