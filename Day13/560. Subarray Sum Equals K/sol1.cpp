#include <bits/stdc++.h>
using namespace std;

// tc: n logn(map worst case)
// sc: n

int subarraySum(vector<int> &nums, int k)
{
    int prefixSum = 0;
    int cnt = 0;
    unordered_map<int, int> mp; // prefixsum, freq

    mp[0] = 1;
    for (int i : nums)
    {
        prefixSum += i;
        if (mp.find(prefixSum - k) != mp.end())
            cnt += mp[prefixSum - k];
        mp[prefixSum]++;
    }
    return cnt;
}

int main()
{
    return 0;
}