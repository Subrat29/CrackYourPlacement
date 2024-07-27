#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: 3^n (worst case me 3 nbrs h)

int solve(int cell, int numSize, vector<vector<int>> &adj)
{
    if (numSize == 0)
        return 1;

    cout << "hii2" << endl;

    int totWays = 0;
    for (auto &&nbr : adj[cell])
    {
        totWays += solve(nbr, numSize - 1, adj);
    }
    return totWays;
}

int knightDialer(int n)
{
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}};

    int cnt = 0;
    for (int i = 0; i <= 9; i++)
    {
        cout << "hii1" << endl;
        cnt += solve(i, n - 1, adj);
    }
    return cnt;
}

int main()
{
    cout << "Ans: " << knightDialer(3131);
    return 0;
}