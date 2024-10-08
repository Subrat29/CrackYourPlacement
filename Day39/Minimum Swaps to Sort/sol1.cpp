#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());
        int swaps = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            pair<int, int> p = v[i];

            int value = p.first;
            int index = p.second;

            if (i != index)
            {
                swaps++;
                swap(v[i], v[index]);
                i--;
            }
        }
        return swaps;
    }
};

int main()
{
    return 0;
}