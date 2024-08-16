#include <bits/stdc++.h>
using namespace std;

// sc: n*n
// tc: n*n

vector<vector<int>> dp;
unordered_map<int, int> mp;

bool solve(vector<int> &stones, int current_stone_index, int prevStone)
{
    if (current_stone_index == stones.size() - 1)
        return true;

    if (dp[current_stone_index][prevStone] != -1)
        return dp[current_stone_index][prevStone];

    bool ans = false;
    for (int i = -1; i <= 1; i++)
    {
        int nextJump = prevStone + i;
        if (nextJump > 0)
        {
            int nextStone = stones[current_stone_index] + nextJump;
            if (mp.find(nextStone) != mp.end())
                ans = ans || solve(stones, mp[nextStone], nextJump);
        }
    }
    return dp[current_stone_index][prevStone] = ans;
}

bool canCross(vector<int> &stones)
{
    int n = stones.size();
    dp.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
        mp[stones[i]] = i;

    return solve(stones, mp[0], 0);
}

int main()
{
    return 0;
}