#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

bool canJump(vector<int> &nums)
{
    int idx = 0;
    int maxReachIdx = 0;
    while (idx < nums.size() && idx <= maxReachIdx)
    {
        maxReachIdx = max(idx + nums[idx], maxReachIdx);
        idx++;
    }
    return idx == nums.size();
}

int main()
{
    return 0;
}