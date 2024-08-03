#include <bits/stdc++.h>
using namespace std;

// sc: n2 + n
// tc: n2

vector<vector<int>> dp;

int solve(int idx, int prev, vector<int> &nums)
{
    if (idx >= nums.size())
        return 0;

    if (dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];

    int take = 0, notTake = 0;

    // take
    if (prev == -1 || nums[idx] > nums[prev])
        take = 1 + solve(idx + 1, idx, nums);

    // not take
    notTake = 0 + solve(idx + 1, prev, nums);

    dp[idx][prev + 1] = max(take, notTake);

    return dp[idx][prev + 1];
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    // dp[i][j] denotes max LIS starting from i when nums[j] is previous picked element
    dp.resize(n, vector<int>(n + 1, -1));

    return solve(0, -1, nums);
}

int main()
{
    return 0;
}