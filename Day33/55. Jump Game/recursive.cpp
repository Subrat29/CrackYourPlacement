#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n^n

bool solve(vector<int> &nums, int idx)
{
    if (idx >= nums.size() - 1)
        return true;

    bool ans = false;
    for (int i = 1; i <= nums[idx]; i++)
    {
        ans = ans || solve(nums, idx + i);
    }
    return ans;
}

bool canJump(vector<int> &nums)
{
    return solve(nums, 0);
}

int main()
{
    return 0;
}