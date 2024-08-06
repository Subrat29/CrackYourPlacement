#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

int maximalSquare(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                {
                    int mini = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    dp[i][j] = mini + 1;
                }
                cnt = max(cnt, dp[i][j]);
            }
        }
    }
    return cnt * cnt;
}

int main()
{
    return 0;
}