#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int a = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int b = nums[0] * nums[1] * nums[n - 1];
        return max(a, b);
    }
};

int main()
{
    return 0;
}