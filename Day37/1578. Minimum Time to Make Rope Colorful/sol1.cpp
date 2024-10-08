#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

int minCost(string s, vector<int> &cost)
{
    int res = cost[0], max_cost = cost[0];
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[i - 1])
        {
            res -= max_cost;
            max_cost = 0;
        }
        res += cost[i];
        max_cost = max(max_cost, cost[i]);
    }
    return res - max_cost;
}

int main()
{
    return 0;
}