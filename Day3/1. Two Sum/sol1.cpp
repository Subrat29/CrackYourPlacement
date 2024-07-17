#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = target - nums[i];
        if (mp.find(x) != mp.end())
        {
            return {i, mp[x]};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    return 0;
}