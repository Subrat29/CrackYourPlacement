#include <bits/stdc++.h>
using namespace std;

// sc: n*2 + n = 3n ~ n
// tc: n

// Approach: Top to Bottom 

int solve(vector<int> &prices, int i, bool buy, vector<vector<int>> &dp)
{
    if (i == prices.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy)
    {
        int buyStock = -prices[i] + solve(prices, i + 1, false, dp);
        int skipStock = 0 + solve(prices, i + 1, true, dp);
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] + solve(prices, i + 1, true, dp);
        int skipStock = 0 + solve(prices, i + 1, false, dp);
        profit = max(sellStock, skipStock);
    }
    dp[i][buy] = profit;
    return dp[i][buy];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1)); // not neccessary to use n+1
    return solve(prices, 0, true, dp);
}

int main()
{
    return 0;
}