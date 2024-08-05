#include <bits/stdc++.h>
using namespace std;

// sc: n*k +  n (recursive stack)
// tc: n*k

vector<vector<int>> dp;

int solve(int idx, int currSpaces, int &k, vector<int> &nums)
{
    if (idx == nums.size())
        return 0;

    if (dp[idx][currSpaces] != -1)
        return dp[idx][currSpaces];

    int newSpaces = currSpaces + 1 + nums[idx];

    // continue on same line
    int sameLine = INT_MAX;
    if (newSpaces <= k)
        sameLine = solve(idx + 1, newSpaces, k, nums);

    // start from new line
    int nextLine = solve(idx + 1, nums[idx], k, nums) + (k - currSpaces) * (k - currSpaces);

    return dp[idx][currSpaces] = min(sameLine, nextLine);
}

int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();
    dp.resize(n + 1, vector<int>(k + 1, -1));
    return solve(1, nums[0], k, nums);
}

int main()
{
    return 0;
}