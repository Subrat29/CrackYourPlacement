#include <bits/stdc++.h>
using namespace std;

// sc: 3^n
// tc: n

bool solve(vector<int> &stones, int current_stone_index, int prevStone, unordered_map<int, int> &mp)
{
    // base case
    if (current_stone_index == stones.size() - 1)
        return true;

    for (int i = -1; i <= 1; i++)
    {
        int nextJump = prevStone + i;
        if (nextJump > 0)
        {
            int nextStone = stones[current_stone_index] + nextJump;
            if (mp.find(nextStone) != mp.end())
                if (solve(stones, mp[nextStone], nextJump, mp))
                    return true;
        }
    }
    return false;
}

bool canCross(vector<int> &stones)
{
    int n = stones.size();

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[stones[i]] = i;

    return solve(stones, mp[0], 0, mp);
}

int main()
{
    return 0;
}