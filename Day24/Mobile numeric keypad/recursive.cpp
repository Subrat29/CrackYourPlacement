#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: 5^n (5 moves possble from digit 5)

long long dfs(int i, int n, vector<vector<int>> &keypad)
{
    if (n == 0)
        return 1;

    long long cnt = 0;
    for (auto &&nbr : keypad[i])
    {
        cnt += dfs(nbr, n - 1, keypad);
    }
    return cnt;
}

long long getCount(int n)
{
    vector<vector<int>> keypad = {
        {0, 8},          // Key 0
        {1, 2, 4},       // Key 1
        {2, 1, 3, 5},    // Key 2
        {3, 2, 6},       // Key 3
        {4, 1, 5, 7},    // Key 4
        {5, 2, 4, 6, 8}, // Key 5
        {6, 3, 5, 9},    // Key 6
        {7, 4, 8},       // Key 7
        {8, 5, 7, 9, 0}, // Key 8
        {9, 6, 8}        // Key 9
    };

    long long ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += dfs(i, n - 1, keypad);
    }
    return ans;
}

int main()
{
    return 0;
}