#include <bits/stdc++.h>
using namespace std;

// tc: O(2^(prices.size() * 2*k))
// sc: O(prices.size())

// By Transaction numbers

int solve(int &k, vector<int> &prices, int idx, int transactionNo)
{
    if (idx == prices.size())
        return 0;
    if (transactionNo == 2 * k)
        return 0;

    int profit = 0;

    // buy
    if (transactionNo % 2 == 0)
    {
        int buy = -prices[idx] + solve(k, prices, idx + 1, transactionNo + 1);
        int skip = 0 + solve(k, prices, idx + 1, transactionNo);
        profit = max(buy, skip);
    }
    // sell
    else
    {
        int sell = prices[idx] + solve(k, prices, idx + 1, transactionNo + 1);
        int skip = 0 + solve(k, prices, idx + 1, transactionNo);
        profit = max(sell, skip);
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices)
{
    return solve(k, prices, 0, 0);
}

int main()
{
    return 0;
}