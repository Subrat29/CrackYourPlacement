#include <bits/stdc++.h>
using namespace std;

// sc: n * amount
// tc: n * amount

void solve(vector<int> &coins, int idx, int coin, int &minCoins, int amount, vector<vector<int>> &memo)
{
    // Base cases
    if (idx == coins.size() || amount < 0)
        return;
    if (amount == 0)
    {
        minCoins = min(minCoins, coin);
        return;
    }
    if (memo[idx][amount] != -1)  // Check if the result is already computed
    {
        if (memo[idx][amount] <= coin)  // If memoized result is worse or same, no need to proceed
            return;
    }
    memo[idx][amount] = coin;  // Memoize the result

    // Include the current coin
    solve(coins, idx, coin + 1, minCoins, amount - coins[idx], memo);
    // Exclude the current coin
    solve(coins, idx + 1, coin, minCoins, amount, memo);
}

int coinChange(vector<int> &coins, int amount)
{
    int minCoins = INT_MAX;
    vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));  // Initialize memo table
    solve(coins, 0, 0, minCoins, amount, memo);
    return (minCoins == INT_MAX) ? -1 : minCoins;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins needed: " << coinChange(coins, amount) << endl;  // Output should be 3
    return 0;
}
