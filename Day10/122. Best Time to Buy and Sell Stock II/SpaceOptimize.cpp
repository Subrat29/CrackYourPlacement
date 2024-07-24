#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> next(2, 0);
    vector<int> curr(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyStock = -prices[i] + next[0];
                int skipStock = 0 + next[1];
                profit = max(buyStock, skipStock);
            }
            else
            {
                int sellStock = prices[i] + next[1];
                int skipStock = 0 + next[0];
                profit = max(sellStock, skipStock);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int main()
{
    return 0;
}