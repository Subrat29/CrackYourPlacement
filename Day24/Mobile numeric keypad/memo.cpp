#include <bits/stdc++.h>
using namespace std;

// Space Complexity: O(n * 10) - for the dp table where n is the length of the number sequence
// Time Complexity: O(10 * n) - for the dp table computation

vector<vector<long long>> dp;

long long dfs(int i, int n, vector<vector<int>> &keypad)
{
    if (n == 0)
        return 1;

    if (dp[n][i] != -1)
        return dp[n][i];

    long long cnt = 0;
    for (auto &&nbr : keypad[i])
    {
        cnt += dfs(nbr, n - 1, keypad);
    }
    return dp[n][i] = cnt;
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

    dp.resize(n + 1, vector<long long>(10, -1));
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