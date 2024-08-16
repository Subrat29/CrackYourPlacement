#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Initialize with 0

    // Base case: If t is empty, there is exactly one subsequence of s that matches (empty subsequence)
    for (int i = 0; i <= n; i++) // Updated loop to include n
    {
        dp[i][m] = 1; // Updated to correctly set the base case when j = m
    }

    // Fill dp array in bottom-up manner
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            // If characters match, add the ways by including and excluding the current character
            if (s[i] == t[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            }
            else
            {
                dp[i][j] = dp[i + 1][j]; // If characters don't match, skip the character in s
            }
        }
    }

    return dp[0][0]; // Final answer is in dp[0][0]
}

int main()
{
    return 0;
}
