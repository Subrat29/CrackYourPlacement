#include <bits/stdc++.h>
using namespace std;

// For each amount, we iterate through all coins, so the number of operations is proportional to number of coins
// sc: amount
// tc: no of coins * amount

vector<int> dp;

int solve(vector<int> &coins, int amount)
{
    if (amount < 0)
        return INT_MAX;

    if (amount == 0)
        return 0;

    if (dp[amount] != -1)
        return dp[amount];

    int minCoins = INT_MAX;
    for (int coin : coins)
    {
        int res = solve(coins, amount - coin);
        if (res != INT_MAX)
            minCoins = min(minCoins, res + 1);
    }

    dp[amount] = minCoins;

    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    dp.resize(amount + 1, -1);

    int minCoins = solve(coins, amount);

    return (minCoins == INT_MAX) ? -1 : minCoins;
}

int main()
{
    return 0;
}