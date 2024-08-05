#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

int countSquares(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 1)
            {
                // Handle the first row and first column
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1; // Single cell square
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                cnt += dp[i][j]; // Count squares
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}