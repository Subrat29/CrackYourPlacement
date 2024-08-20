#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimalChocolateBreakingCost(int m, int n, vector<int> &x, vector<int> &y)
{
    // Sort the costs in descending order
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());

    int i = 0, j = 0;
    int horizontal_pieces = 1, vertical_pieces = 1;
    int cost = 0;

    // Greedily choose the cuts
    while (i < m - 1 && j < n - 1)
    {
        if (x[i] > y[j])
        {
            cost += x[i] * vertical_pieces; // Vertical cut affects current vertical pieces
            horizontal_pieces++;
            i++;
        }
        else
        {
            cost += y[j] * horizontal_pieces; // Horizontal cut affects current horizontal pieces
            vertical_pieces++;
            j++;
        }
    }

    // Add remaining vertical cuts
    while (i < m - 1)
    {
        cost += x[i] * vertical_pieces;
        i++;
    }

    // Add remaining horizontal cuts
    while (j < n - 1)
    {
        cost += y[j] * horizontal_pieces;
        j++;
    }

    return cost;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> x(m - 1), y(n - 1);

        for (int i = 0; i < m - 1; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> y[i];
        }

        int result = minimalChocolateBreakingCost(m, n, x, y);
        cout << result << endl;
    }

    return 0;
}

int main()
{
    return 0;
}