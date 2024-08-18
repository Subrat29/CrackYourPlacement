#include <bits/stdc++.h>
using namespace std;

// tc: n*2*k
// sc: n*2*k + n

// By Transaction numbers

vector<vector<int>> dp;

int solve(int &k, vector<int> &prices, int idx, int transactionNo)
{
    if (idx == prices.size())
        return 0;
    if (transactionNo == 2 * k)
        return 0;
    if (dp[idx][transactionNo] != -1)
        return dp[idx][transactionNo];

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
    return dp[idx][transactionNo] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    dp.resize(n, vector<int>(2 * k, -1)); // index, operationNo

    return solve(k, prices, 0, 0);
}

int main()
{
    return 0;
}