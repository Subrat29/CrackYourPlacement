#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

// Approach: Bottom to Top

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for (int i = n-1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyStock = -prices[i] + dp[i+1][0];
                int skipStock = 0 + dp[i+1][1];
                profit = max(buyStock, skipStock);
            }
            else
            {
                int sellStock = prices[i] + dp[i+1][1];
                int skipStock = 0 + dp[i+1][0];
                profit = max(sellStock, skipStock);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int main()
{
    return 0;
}