#include <bits/stdc++.h>
using namespace std;

// sc: n*9
// tc: n*9 (exclude 5)

// Bottom Up Approach

int knightDialer(int n)
{
    int mod = 1e9 + 7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}};

    vector<vector<int>> dp(n + 1, vector<int>(10, 0));

    for (int i = 0; i <= 9; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            int totWays = 0;
            for (auto &&nbr : adj[j])
                totWays = (totWays + dp[i - 1][nbr]) % mod;

            dp[i][j] = totWays;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= 9; i++)
        cnt = (cnt + dp[n - 1][i]) % mod;

    return cnt % mod;
}

int main()
{
    cout << "Ans: " << knightDialer(3131);
    return 0;
}