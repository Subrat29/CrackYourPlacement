#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[nums[i]])
            return nums[i];
        else
            mp[nums[i]] = 1;
    }
    return -1;
}

int main()
{
    return 0;
}