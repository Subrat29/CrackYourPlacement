#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

class NumArray
{
public:
    vector<int> &preSum;

    NumArray(vector<int> &nums) : preSum(nums)
    {
        for (int i = 1; i < preSum.size(); ++i)
            preSum[i] += preSum[i - 1];
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return preSum[right];
        return preSum[right] - preSum[left - 1];
    }
};

int main()
{
    return 0;
}