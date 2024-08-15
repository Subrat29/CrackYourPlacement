#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

// User function Template for C++

class Solution
{
public:
    int dp[100][100];
    int find(int keys[], int freq[], int l, int r)
    {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];
        int mini = INT_MAX;
        int sum = 0;
        for (int i = l; i <= r; i++)
            sum += freq[i];
        for (int i = l; i <= r; i++)
        {
            int left = find(keys, freq, l, i - 1);
            int right = find(keys, freq, i + 1, r);

            mini = min(mini, sum + left + right);
        }

        return dp[l][r] = mini;
    }

    int optimalSearchTree(int keys[], int freq[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return find(keys, freq, 0, n - 1);
    }
};

int main()
{
    return 0;
}