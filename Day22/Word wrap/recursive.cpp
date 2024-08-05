#include <bits/stdc++.h>
using namespace std;

// sc: n (recursive stack)
// tc: 2^n

int solve(int idx, int currSpaces, int &k, vector<int> &nums)
{
    if (idx == nums.size())
        return 0;

    int newSpaces = currSpaces + 1 + nums[idx];

    // continue on same line
    int sameLine = INT_MAX;
    if (newSpaces <= k)
        sameLine = solve(idx + 1, newSpaces, k, nums);

    // start from new line
    int nextLine = solve(idx + 1, nums[idx], k, nums) + (k - currSpaces) * (k - currSpaces);

    return min(sameLine, nextLine);
}

int solveWordWrap(vector<int> nums, int k)
{
    return solve(1, nums[0], k, nums);
}

int main()
{
    return 0;
}