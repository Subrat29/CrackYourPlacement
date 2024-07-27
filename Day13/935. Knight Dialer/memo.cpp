#include <bits/stdc++.h>
using namespace std;

// sc: n*9
// tc: n*9 (exclude 5)

int mod = 1e9 + 7;
vector<vector<int>> dp;

int solve(int cell, int numSize, vector<vector<int>> &adj)
{
    if (numSize == 0)
        return 1;

    if (dp[numSize][cell] != -1)
        return dp[numSize][cell];

    int totWays = 0;
    for (auto &&nbr : adj[cell])
        totWays = (totWays + solve(nbr, numSize - 1, adj)) % mod;

    dp[numSize][cell] = totWays;

    return totWays;
}

int knightDialer(int n)
{
    dp.resize(n + 1, vector<int>(10, -1));
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

    int cnt = 0;
    for (int i = 0; i <= 9; i++)
        cnt = (cnt + solve(i, n - 1, adj)) % mod;

    return cnt % mod;
}

int main()
{
    cout << "Ans: " << knightDialer(3131);
    return 0;
}