#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

int subarraysDivByK(vector<int> &nums, int k)
{

    unordered_map<int, int> remFrequency;
    remFrequency[0] = 1;

    int sum = 0;
    int rem = 0;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        rem = sum % k;

        // if rem is negative then add k eg. -1 = (-1+5) = 4
        if (rem < 0)
        {
            rem += k;
        }

        if (remFrequency.find(rem) != remFrequency.end())
        {
            ans += remFrequency[rem];
        }
        remFrequency[rem]++;
    }
    return ans;
}

int main()
{
    return 0;
}