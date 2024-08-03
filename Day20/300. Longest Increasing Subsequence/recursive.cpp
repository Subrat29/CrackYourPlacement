#include <bits/stdc++.h>
using namespace std;

// sc: n (recursive stack depth)
// tc: 2^n

// At each index, we have choice to either take or not take the element and we explore both ways.
// So, we 2 * 2 * 2...N times = O(2^N)

int solve(int idx, int prev, vector<int> &nums)
{
    if (idx == nums.size())
        return 0;

    int take = 0, notTake = 0;

    // take
    if (nums[idx] > prev)
        take = 1 + solve(idx + 1, nums[idx], nums);

    // not take
    notTake = 0 + solve(idx + 1, prev, nums);

    return max(take, notTake);
}

int lengthOfLIS(vector<int> &nums)
{
    return solve(0, INT_MIN, nums);
}

int main()
{
    return 0;
}