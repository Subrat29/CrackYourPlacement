#include <bits/stdc++.h>
using namespace std;

// tc: n^amount
// sc: amount

int solve(vector<int> &coins, int amount)
{
    if (amount < 0)
        return INT_MAX;

    if (amount == 0)
        return 0;

    int minCoins = INT_MAX;
    for (int coin : coins)
    {
        int res = solve(coins, amount - coin);
        if (res != INT_MAX)
            minCoins = min(minCoins, res + 1);
    }

    return minCoins;
}

int coinChange(vector<int> &coins, int amount)
{
    int minCoins = solve(coins, amount);

    return (minCoins == INT_MAX) ? -1 : minCoins;
}

int main()
{
    return 0;
}