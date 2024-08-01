#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: 2^n * amount

void solve(vector<int> &coins, int idx, int coin, int &minCoins, int amount)
{
    if (idx == coins.size() || amount < 0)
        return;
    if (amount == 0)
    {
        minCoins = min(minCoins, coin);
        return;
    }

    // Include the current coin
    solve(coins, idx, coin + 1, minCoins, amount - coins[idx]);
    // Exclude the current coin
    solve(coins, idx + 1, coin, minCoins, amount);
}

int coinChange(vector<int> &coins, int amount)
{
    int minCoins = INT_MAX;
    solve(coins, 0, 0, minCoins, amount);
    return (minCoins == INT_MAX) ? -1 : minCoins;
}

int main()
{
    return 0;
}