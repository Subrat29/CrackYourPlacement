#include <bits/stdc++.h>
using namespace std;

// sc: n (recursive call stack)
// tc: 2^n

// Input: prices = [7,1,5,3,6,4]
// Output: 7

int solve(vector<int> &prices, int i, bool buy)
{
    if (i == prices.size())
        return 0;

    int profit = 0;
    if (buy)
    {
        int buyStock = -prices[i] + solve(prices, i + 1, false);
        int skipStock = 0 + solve(prices, i + 1, true);
        profit = max(buyStock, skipStock);
    }
    else
    {
        int sellStock = prices[i] + solve(prices, i + 1, true);
        int skipStock = 0 + solve(prices, i + 1, false);
        profit = max(sellStock, skipStock);
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    return solve(prices, 0, true);
}

int main()
{
    return 0;
}