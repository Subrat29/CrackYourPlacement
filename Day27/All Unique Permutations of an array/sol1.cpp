#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

// User function Template for C++

class Solution
{
public:
    vector<vector<int>> uniquePerms(vector<int> &nums, int n)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> temp;
        do
        {

            temp.push_back(nums);

        } while (next_permutation(nums.begin(), nums.end()));

        return temp;
    }
};

int main()
{
    return 0;
}