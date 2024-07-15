#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int buyPrice = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < buyPrice)
        {
            buyPrice = prices[i];
        }

        int sellPrice = prices[i] - buyPrice;
        if (sellPrice > maxProfit)
        {
            maxProfit = sellPrice;
        }
    }
    return maxProfit;
}

int main()
{
    return 0;
}